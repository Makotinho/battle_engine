#include <pokeagb/pokeagb.h>
#include "battle_data/pkmn_bank.h"
#include "battle_data/pkmn_bank_stats.h"
#include "battle_data/battle_state.h"
#include "battle_text/battle_textbox_gfx.h"

extern void validate_player_selected_move(void);
extern void vblank_cb_no_merge(void);
extern void vblank_cb_merge_move_select(void);
extern void load_icons_moves(u8 bank);
extern void update_cursor_move_select(u8 task_id);
extern void show_move_data(void);
extern void init_selection_cursor(u8 mode, u8 bank);
extern void dprintf(const char * str, ...);
extern void option_selection2(void);
extern void switch_scene_main(void);
extern void free_unused_objs(void);

/* Fight menu and move menu selection. Preperation to go into battle loop*/

#define SELECTING_BANK battle_master->option_selecting_bank

enum BattleMenuSelectionOptions {
    BaseMenuInitialize = 0,
    BaseMenuInputInterpret,
    FightOptionSelected_FirstTime,
    FightOptionSelected_FastLoad,
    SwitchOptionSelected,
    BagOptionSelected,
    RunOptionSelected,
    MenuWaitState,
    MoveSelectedExit,
};

/* Fight menu and move menu selection. Preperation to go into battle loop*/
void option_selection(u8 bank)
{
    battle_master->option_selecting_bank = bank;
    // check bank is skipping selection via move
    if ((HAS_VOLATILE(bank, VOLATILE_CHARGING)) ||
        (p_bank[bank]->b_data.skip_move_select) ||
        (HAS_VOLATILE(bank, VOLATILE_RECHARGING))) {
        // jump straight to move validation
        set_callback1(validate_player_selected_move);
        return;
    }
    set_callback1(option_selection2);
    super.multi_purpose_state_tracker = BaseMenuInitialize;
}


void option_selection2()
{
    while (peek_message())
        return;
    switch (super.multi_purpose_state_tracker) {
        case BaseMenuInitialize:
        {
            // initialize fight menu selection
            vblank_handler_set(vblank_cb_no_merge);
            void* map_base = (void *)0x600F800;
            memcpy(map_base, battle_textbox_action_selectMap, sizeof(battle_textbox_action_selectMap));
            init_selection_cursor(1, 0);

            // next state
            bs_anim_status = 1;
            super.multi_purpose_state_tracker = BaseMenuInputInterpret;
            break;
        }
        case BaseMenuInputInterpret:
            // wait for input selection from fight menu
            if (bs_anim_status)
                return;
            // interpret selection
            switch (battle_master->selected_option) {
                case OPTION_FIGHT:
                    if (battle_master->fight_menu_content_spawned) {
                        super.multi_purpose_state_tracker = FightOptionSelected_FastLoad;
                    } else {
                        super.multi_purpose_state_tracker = FightOptionSelected_FirstTime;
                    }
                    break;
                case OPTION_POKEMON:
                    super.multi_purpose_state_tracker = SwitchOptionSelected;
                    break;
                case OPTION_BAG:
                    super.multi_purpose_state_tracker = BagOptionSelected;
                    break;
                case OPTION_RUN:
                    super.multi_purpose_state_tracker = RunOptionSelected;
                    break;

            };
            break;
        case FightOptionSelected_FirstTime:
            /* FIGHT selected from fight menu */

            // update tilemap
            vblank_handler_set(vblank_cb_merge_move_select);
            void* map_base = (void *)0x600F800;
            memcpy(map_base, battle_textbox_move_selectMap, sizeof(battle_textbox_action_selectMap));

            // init cursor
            init_selection_cursor(0, 0);

            // init move types
            load_icons_moves(SELECTING_BANK);
            // set into pause state
            bs_anim_status = 1;
            super.multi_purpose_state_tracker = MenuWaitState;
            break;
        case FightOptionSelected_FastLoad:
            {
                vblank_handler_set(vblank_cb_merge_move_select);
                void* map_base = (void *)0x600F800;
                memcpy(map_base, battle_textbox_move_selectMap, sizeof(battle_textbox_action_selectMap));
                show_move_data();
                tasks[task_add(update_cursor_move_select, 1)].priv[0] = 0;
                bs_anim_status = 1;
                super.multi_purpose_state_tracker = MenuWaitState;
                break;
            }
        case SwitchOptionSelected:
            // POKEMON selection from fight menu
            fade_screen(0xFFFFFFFF, 0, 0, 16, 0x0000);
            super.multi_purpose_state_tracker = 0;
            set_callback1(switch_scene_main);
            break;
        case BagOptionSelected:
            // BAG selected from fight menu
            break;
        case RunOptionSelected:
        {
            // RUN selected from fight menu
            p_bank[SELECTING_BANK]->b_data.is_running = true;
            super.multi_purpose_state_tracker = MoveSelectedExit;
            break;
        }
        case MenuWaitState:
            break;
        case MoveSelectedExit:
        {
            free_unused_objs();
            battle_master->fight_menu_content_spawned  = 0;
            set_callback1(validate_player_selected_move);
            super.multi_purpose_state_tracker = 0;
            break;
        }
        case 9:
            // pick move validator function based on battle type
            return;
    };
}
