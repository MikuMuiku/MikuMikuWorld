#pragma once
#include <unordered_map>
#include <string>

namespace MikuMikuWorld
{
	extern std::unordered_map<std::string, std::string> en
	{
		// Menu bar
		{"file", "File"},
		{"new", "New"},
		{"open", "Open"},
		{"open_recent", "Open Recent"},
		{"clear", "Clear"},
		{"save", "Save"},
		{"save_as", "Save As"},
		{"export", "Export"},
		{"exit", "Exit"},
		{"edit", "Edit"},
		{"undo", "Undo"},
		{"redo", "Redo"},
		{"select_all", "Select All"},
		{"view", "View"},
		{"show_step_outlines", "Show Step Outlines"},
		{"hide_step_outlines_in_playback", "Hide Step Outlines During Playback"},
		{"draw_waveform", "Show Waveform"},
		{"import_preset", "Import Preset"},
		{"reload_presets", "Reload Presets"},
		{"open_presets_folder", "Open Presets Folder"},
		{"settings", "Settings"},
		{"window", "Window"},
		{"vsync", "VSync"},
		{"show_fps", "Show FPS"},
		{"debug", "Debug"},
		{"create_auto_save", "Create Auto Save"},
		{"help", "Help"},
		{"about", "About"},

		// Dialogs
		{"file_not_found", "File not found"},
		{"file_not_found_msg1", "The file"},
		{"file_not_found_msg2", "was not found"},
		{"remove_recent_file_not_found", "Do you want to remove it from the recent files list?"},
		{"yes", "Yes"},
		{"no", "No"},
		{"unsaved_changes", "Unsaved Changes"},
		{"ask_save", "Save current changes?"},
		{"warn_unsaved", "Any unsaved changes will be lost."},
		{"save_changes", "Save Changes"},
		{"discard_changes", "Discard Changes"},
		{"score_file", "Score file"},
		{"error", "Error"},
		{"error_load_score_file", "An error occurred while reading the score file"},
		{"error_load_music_file", "Cannot open music file"},
		{"cancel", "Cancel"},
		{"general", "General"},
		{"key_config", "Key Config"},
		{"language", "Language"},
		{"auto", "Auto"},
		{"auto_save", "Auto Save"},
		{"auto_save_enable", "Auto Save Enabled"},
		{"auto_save_interval", "Auto Save Interval (min)"},
		{"auto_save_count", "Maximum Auto Save Entries"},
		{"theme", "Theme"},
		{"base_theme", "Base Theme"},
		{"theme_light", "Light"},
		{"theme_dark", "Dark"},
		{"accent_color", "Accent Color"},
		{"accent_color_help", "Select an accent color to apply. The first slot can be customized from the color controls below."},
		{"select_accent_color", "Select an accent color."},
		{"display_mode", "Display Mode"},
		{"custom_color", "Custom Color"},
		{"language", "Language"},
		{"timeline", "Timeline"},
		{"match_notes_size_to_timeline", "Match notes size to timeline width"},
		{"lane_width", "Lane Width"},
		{"notes_height", "Notes Height"},
		{"scrolling", "Scrolling"},
		{"scroll_speed_normal", "Scroll Speed"},
		{"scroll_speed_shift", "Scroll Speed (Shift)"},
		{"use_smooth_scroll", "Use Smooth Scrolling"},
		{"smooth_scroll_time", "Smooth Scrolling Time"},
		{"return_to_last_tick", "Return To Last Tick On Pause" },
		{"cursor_auto_scroll", "Cursor Auto Scroll"},
		{"cursor_auto_scroll_amount", "Cursor Auto Scroll Percentage From Timeline"},
		{"background", "Background"},
		{"background_image", "Background Image"},
		{"draw_background", "Draw Background Image"},
		{"background_brightnes", "Background Brightness"},
		{"lanes_opacity", "Lanes Opacity"},
		{"video", "Video"},
		{"notes_se", "Notes SE"},

		// Score editor
		{"chart_properties", "Chart Properties"},
		{"notes_timeline", "Notes Timeline"},
		{"options", "Options"},
		{"select", "Select"},
		{"tap", "Tap"},
		{"hold", "Hold"},
		{"hold_step", "Hold Mid"},
		{"flick", "Flick"},
		{"critical", "Critical"},
		{"trace", "Trace"},
		{"guide", "Guide"},
		{"bpm", "BPM"},
		{"time_signature", "Time Signature"},
		{"none", "None"},
		{"follow_cursor", "Follow Cursor"},
		{"up", "Up"},
		{"default", "Default"},
		{"left", "Left"},
		{"right", "Right"},
		{"normal", "Normal"},
		{"hidden", "Hidden"},
		{"skip", "Skip"},
		{"linear", "Linear"},
		{"ease_in", "Ease In"},
		{"ease_out", "Ease Out"},
		{"delete", "Delete"},
		{"copy", "Copy"},
		{"cut", "Cut"},
		{"paste", "Paste"},
		{"flip_paste", "Flip Paste"},
		{"flip", "Flip"},
		{"note_width", "Note Width"},
		{"shrink_down", "Shrink Down"},
		{"shrink_up", "Shrink Up"},
		{"connect_holds", "Connect Holds"},
		{"split_hold", "Split Hold"},
		{"step_type", "Step Type"},
		{"ease_type", "Ease Type"},
		{"flick_type", "Flick Type"},
		{"hold_type", "Hold Type"},
		{"metadata", "Metadata"},
		{"title", "Title"},
		{"designer", "Designer"},
		{"artist", "Artist"},
		{"jacket", "Jacket"},
		{"audio", "Audio"},
		{"music_file", "Music File"},
		{"music_offset", "Music Offset"},
		{"volume_master", "Master Volume"},
		{"volume_bgm", "BGM Volume"},
		{"volume_se", "SE Volume"},
		{"statistics", "Statistics"},
		{"taps", "Taps"},
		{"flicks", "Flicks"},
		{"holds", "Holds"},
		{"steps", "Hold Mids"},
		{"traces", "Traces"},
		{"total", "Total"},
		{"combo", "Combo"},
		{"goto_measure", "Go To Measure"},
		{"division", "Division"},
		{"division_suffix", " Division"},
		{"custom", "Custom "},
		{"custom_division", "Custom Division"},
		{"zoom", "Zoom"},
		{"edit_bpm", "Edit Tempo"},
		{"tick", "Tick"},
		{"remove", "Remove"},
		{"edit_time_signature", "Edit Time Signature"},
		{"measure", "Measure"},
		{"skill", "Skill"},
		{"increase_note_size", "Increase Note Size"},
		{"decrease_note_size", "Decrease Note Size"},
		{"hi_speed", "Hi-Speed"},
		{"edit_hi_speed", "Edit Hi-Speed"},
		{"hi_speed_speed", "Speed"},
		{"edit_skill", "Edit Skill Trigger"},
		{"edit_fever", "Edit FEVER Trigger"},
		{"edit_none", "Edit"},
		{"edit_event", "Edit Event"},

		// Presets
		{"presets", "Presets"},
		{"no_presets", "No presets available"},
		{"name", "Name"},
		{"description", "Description"},
		{"create_preset", "Create Preset"},
		{"search", "Search..."},
		{"confirm", "Confirm"},
		{"preset_deleted", "Preset deleted"},
		{"close", "Close"},

		// Shortcuts
		{"action", "Action"},
		{"keys", "Keys"},
		{"add", "Add"},
		{"cmd_key_listen", "Waiting for input..."},
		{"new_chart", "New Chart"},
		{"cancel_paste", "Cancel Paste"},
		{"toggle_playback", "Play / Pause"},
		{"stop", "Stop"},
		{"previous_tick", "Previous Tick"},
		{"next_tick", "Next Tick"},
		{"timeline_select", "Timeline - Select"},
		{"timeline_tap", "Timeline - Insert Tap"},
		{"timeline_hold", "Timeline - Insert Hold"},
		{"timeline_hold_step", "Timeline - Insert Hold Mid"},
		{"timeline_flick", "Timeline - Insert Flick"},
		{"timeline_critical", "Timeline - Insert Critical"},
		{"timeline_trace", "Timeline - Insert Trace"},
		{"timeline_guide", "Timeline - Insert Guide"},
		{"timeline_bpm", "Timeline - Insert BPM"},
		{"timeline_time_signature", "Timeline - Insert Time Signature"},
		{"timeline_hi_speed", "Timeline - Insert Hi-Speed Change"},
		{"zoom_in", "Zoom In"},
		{"zoom_out", "Zoom Out"}
	};
}
