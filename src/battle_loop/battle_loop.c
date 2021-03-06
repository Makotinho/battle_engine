#include <pokeagb/pokeagb.h>
#include "battle_data/pkmn_bank.h"
#include "battle_data/pkmn_bank_stats.h"
#include "battle_data/battle_state.h"
#include "moves/moves.h"
#include "battle_text/battle_pick_message.h"
#include "move_chain_states.h"

extern void run_move(void);
extern void dprintf(const char * str, ...);
extern void reset_turn_bits(u8 bank);
extern void run_after_switch(void);
extern void option_selection(u8 bank);
extern void on_faint(void);
extern void run_switch(void);
extern void sync_battler_struct(u8 bank);
extern bool enqueue_message(u16 move, u8 bank, enum battle_string_ids id, u16 effect);
extern u8 count_usable_moves(u8 bank);

void run_decision(void)
{
    while (peek_message())
        return;

    u8 bank_index = (battle_master->execution_index) ? battle_master->second_bank : battle_master->first_bank;
    switch (super.multi_purpose_state_tracker) {
       case S_RUN_SWITCH:
            set_callback1(run_switch);
            super.multi_purpose_state_tracker = S_CHECK_FLEEING;
            break;
        case S_RUN_AFTER_SWITCH:
            set_callback1(run_after_switch);
            super.multi_purpose_state_tracker = S_RUN_FLEE;
            break;
        case S_RUN_SWITCH_ALTERNATE_BANK:
        {
            // once first bank's run_switch and run_after_switch have exec'd, run second bank
            if (battle_master->execution_index) {
                // if second bank run, switch back to first bank and go to next phase
                battle_master->execution_index = 0;
                super.multi_purpose_state_tracker = S_RUN_MOVE;
            } else {
                battle_master->execution_index = 1;
                super.multi_purpose_state_tracker = S_RUN_SWITCH;
            }
            break;
        }
        case S_RUN_MOVE:
            if ((p_bank[bank_index]->b_data.is_running) && (bank_index == PLAYER_SINGLES_BANK)) {
                super.multi_purpose_state_tracker = S_RUN_MOVE_ALTERNATE_BANK;
            } else {
                set_callback1(run_move);
                super.multi_purpose_state_tracker = S_BEFORE_MOVE;
            }
            break;
        case S_RUN_MOVE_ALTERNATE_BANK:
            // run move for second bank after first bank is run.
            if (battle_master->execution_index) {
                battle_master->execution_index = 0;
                super.multi_purpose_state_tracker = S_UPDATE_TURN_CALLBACKS;
            } else {
                battle_master->execution_index = 1;
                super.multi_purpose_state_tracker = S_RUN_MOVE;
            }
            break;
        case S_UPDATE_TURN_CALLBACKS:
            update_callbacks();
            super.multi_purpose_state_tracker = S_SOFT_RESET_BANK;
            break;
        case S_SOFT_RESET_BANK:
        {
            // reset turn based bits
            p_bank[PLAYER_SINGLES_BANK]->b_data.first_turn = false;
            p_bank[OPPONENT_SINGLES_BANK]->b_data.first_turn = false;
            reset_turn_bits(battle_master->first_bank);
            reset_turn_bits(battle_master->second_bank);
            option_selection(0);
            super.multi_purpose_state_tracker = 0;
            battle_master->execution_index = 0;
            break;
        }
        case S_END_BATTLE:
            // TODO: free resources
            sync_battler_struct(PLAYER_SINGLES_BANK);
            exit_to_overworld_2_switch();
            set_callback1(c1_overworld);
            break;
        default:
            break;
    };
}

extern void wild_ai_pick_attack(u8 bank);
extern bool validate_move_player(u8 bank);

void validate_player_selected_move()
{
    extern void battle_set_order(void);
    extern u16 bank_interpret_selected_move(u16);
    // get and set currently selected move
    u16 move_player = bank_interpret_selected_move(PLAYER_SINGLES_BANK);
    CURRENT_MOVE(PLAYER_SINGLES_BANK) = move_player;
    if (!validate_move_player(PLAYER_SINGLES_BANK)) {
        option_selection(PLAYER_SINGLES_BANK);
        return;
    }
    wild_ai_pick_attack(OPPONENT_SINGLES_BANK);

    // A usable move was picked
	battle_set_order();
    battle_master->execution_index = 0;
	set_callback1(run_decision);
}


void validate_selected_move()
{

}
