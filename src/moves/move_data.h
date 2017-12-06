#ifndef MOVE_DATA_H_
#define MOVE_DATA_H_

#include <pokeagb/pokeagb.h>
#include "moves.h"
#include "../anonymous_callbacks/anonymous_callbacks.h"


/* Move callback funcs */
extern void payday_ondmg(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 ohko_tryhit_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 solarbeam_before_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 solarblade_before_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 freeze_shock_before_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 ice_burn_before_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 razor_wind_before_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 sky_attack_before_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 fly_before_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 gust_on_modify(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 whirlwind_on_tryhit_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 whirlwind_on_effect_cb(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern void acrobatics_on_base_power_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 bind_on_effect_cb(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 minimize_on_effect_cb(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 stomp_on_modify_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 jump_kick_on_move_fail(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 bodyslam_on_modify_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 thrash_on_tryhit_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 thrash_on_move_fail(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern void thrash_on_after_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern void sonic_boom_on_dmg(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 disable_on_effect_cb(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 rollout_on_before_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 rollout_on_move_fail(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern void rollout_on_base_power_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 metronome_on_modify_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 mirror_move_on_modify_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 sleep_talk_before_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 sleep_talk_on_modify_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 assist_on_modify_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 copycat_on_modify_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 clear_smog_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 magic_coat_on_tryhit(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 me_first_on_tryhit(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 snatch_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 conversion_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 conversion_two_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 reflect_type_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 soak_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 flying_press_on_modify_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern void flying_press_on_base_power(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 trick_or_treat_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 rest_on_tryhit_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 ion_deluge_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 electrify_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 electrify_on_tryhit(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern void psywave_on_damage_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 burn_up_on_tryhit(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 burn_up_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 protect_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 protection_on_tryhit(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern void seismic_toss_on_damage_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 cotton_spore_on_tryhit_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern void endure_on_damage(u8 user, u8 source, u16 move, struct anonymous_callback* acb);
extern u8 endure_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 wide_guard_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 mat_block_on_tryhit(u8 user, u8 source, u16 move, struct anonymous_callback* acb);
extern u8 mat_block_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 crafty_shield_on_tryhit(u8 user, u8 source, u16 move, struct anonymous_callback* acb);
extern u8 crafty_shield_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 feint_on_before_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 hyperspace_hole_before_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 shadow_force_on_before_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 phantom_force_on_before_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 present_on_modify_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 reflect_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 light_screen_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 aurora_veil_on_tryhit(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 aurora_veil_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 rain_dance_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 sunny_day_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 hail_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 sandstorm_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 brickbreak_on_tryhit(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 future_sight_on_tryhit(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 wish_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 yawn_on_tryhit(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 yawn_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 charge_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 doom_desire_on_tryhit(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern void counter_before_turn(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 counter_on_tryhit(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 mirror_coat_on_tryhit(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern void mirror_coat_before_turn(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 metal_burst_on_tryhit(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern void metal_burst_before_turn(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 hurricane_on_before_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 hurricane_on_tryhit_inv(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 weather_ball_on_modify_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 electric_terrain_on_effect(u8 bank, u8 src, u16 stat_id, struct anonymous_callback* acb);
extern u8 grassy_terrain_on_effect(u8 bank, u8 src, u16 stat_id, struct anonymous_callback* acb);
extern u8 misty_terrain_on_effect(u8 bank, u8 src, u16 stat_id, struct anonymous_callback* acb);
extern u8 psychic_terrain_on_effect(u8 bank, u8 src, u16 stat_id, struct anonymous_callback* acb);
extern u8 secret_power_on_modify(u8 bank, u8 src, u16 stat_id, struct anonymous_callback* acb);
extern u8 floral_healing_on_modify(u8 bank, u8 src, u16 stat_id, struct anonymous_callback* acb);
extern u8 camouflage_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 nature_power_on_tryhit(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern void water_spout_on_base_power_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern void stored_power_on_base_power_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern void punishment_on_base_power_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 hidden_power_on_modify_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 revelation_dance_on_modify_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 rage_on_effect_move(u8 user, u8 src, u16 move, struct anonymous_callback* acb);
extern u8 mimic_on_effect(u8 user, u8 src, u16 move, struct anonymous_callback* acb);


/* User stats */
extern struct move_procs user_lower_atk_1;
extern struct move_procs user_lower_def_1;
extern struct move_procs user_lower_spAtk_1;
extern struct move_procs user_lower_spDef_1;
extern struct move_procs user_lower_spd_1;
extern struct move_procs user_lower_acc_1;

extern struct move_procs user_lower_atk_2;
extern struct move_procs user_lower_def_2;
extern struct move_procs user_lower_spAtk_2;
extern struct move_procs user_lower_spDef_2;
extern struct move_procs user_lower_spd_2;
extern struct move_procs user_lower_acc_2;

extern struct move_procs user_raise_atk_1;
extern struct move_procs user_raise_def_1;
extern struct move_procs user_raise_spAtk_1;
extern struct move_procs user_raise_spDef_1;
extern struct move_procs user_raise_spd_1;
extern struct move_procs user_raise_acc_1;
extern struct move_procs user_raise_evn_1;

extern struct move_procs user_raise_atk_2;
extern struct move_procs user_raise_def_2;
extern struct move_procs user_raise_spAtk_2;
extern struct move_procs user_raise_spDef_2;
extern struct move_procs user_raise_spd_2;
extern struct move_procs user_raise_acc_2;

/* Target stats */
extern struct move_procs target_lower_atk_1;
extern struct move_procs target_lower_def_1;
extern struct move_procs target_lower_spAtk_1;
extern struct move_procs target_lower_spDef_1;
extern struct move_procs target_lower_spd_1;
extern struct move_procs target_lower_acc_1;

extern struct move_procs target_lower_atk_2;
extern struct move_procs target_lower_def_2;
extern struct move_procs target_lower_def_50_procs;
extern struct move_procs target_lower_spAtk_2;
extern struct move_procs target_lower_spDef_2;
extern struct move_procs target_lower_spd_2;
extern struct move_procs target_lower_acc_2;
extern struct move_procs target_lower_evn_2;

extern struct move_procs target_raise_atk_1;
extern struct move_procs target_raise_def_1;
extern struct move_procs target_raise_spAtk_1;
extern struct move_procs target_raise_spDef_1;
extern struct move_procs target_raise_spd_1;
extern struct move_procs target_raise_acc_1;

extern struct move_procs target_raise_atk_2;
extern struct move_procs target_raise_def_2;
extern struct move_procs target_raise_spAtk_2;
extern struct move_procs target_raise_spDef_2;
extern struct move_procs target_raise_spd_2;
extern struct move_procs target_raise_acc_2;

/* Move Specific procs */
extern struct move_procs poison_20_procs;
extern struct move_procs poison_30_procs;
extern struct move_procs poison_40_procs;
extern struct move_procs poison_100_procs;
extern struct move_procs toxic_procs;
extern struct move_procs supersonic_procs;
extern struct move_procs burn_10_procs;
extern struct move_procs freeze_10_procs;
extern struct move_procs confuse_10_procs;
extern struct move_procs confuse_20_procs;
extern struct move_procs confuse_30_procs;
extern struct move_procs confuse_100_procs;
extern struct move_procs paralyze_10_procs;
extern struct move_procs paralyze_30_procs;
extern struct move_procs shell_smash_procs;
extern struct move_procs dragon_ascent_procs;
extern struct move_procs shift_gear_procs;
extern struct move_procs paralyze_100_procs;
extern struct move_procs bubble_beam_procs;
extern struct move_procs aurora_beam_procs;
extern struct move_procs shadow_ball_procs;
extern struct move_procs psychic_procs;
extern struct move_procs target_lower_acc_1_chance_50;
extern struct move_procs sing_procs;
extern struct move_procs rest_procs;
extern struct move_procs target_raise_atk_2_confuse;
extern struct move_procs user_raise_atk_1_10;
extern struct move_procs target_burn_50;
extern struct move_procs target_lower_def_1_30;
extern struct move_procs user_raise_def_1_10;
extern struct move_procs poison_10_procs;


#endif /* MOVE_DATA_H_ */