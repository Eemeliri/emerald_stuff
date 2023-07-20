EventScript_RepelWoreOff::
	lockall
	checkitem VAR_REPEL_LAST_USED, 1
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_RepelWoreOff_NoMoreRepels
	msgbox Text_RepelWoreOff_UseAnother, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq EventScript_RepelWoreOff_ChooseNo
	copyvar VAR_0x8004, VAR_REPEL_LAST_USED
	callnative ItemId_GetHoldEffectParam_Script
	copyvar VAR_REPEL_STEP_COUNT, VAR_RESULT
	bufferitemname 1, VAR_REPEL_LAST_USED
	removeitem VAR_REPEL_LAST_USED, 1
	playse SE_REPEL
	msgbox gText_PlayerUsedVar2, MSGBOX_SIGN
	goto EventScript_RepelWoreOff_End

EventScript_RepelWoreOff_ChooseNo:
	closemessage
	goto EventScript_RepelWoreOff_End

EventScript_RepelWoreOff_NoMoreRepels:
	msgbox Text_RepelWoreOff, MSGBOX_SIGN

EventScript_RepelWoreOff_End:
	releaseall
	end


EventScript_LureWoreOff::
.if I_REPEL_LURE_MENU == TRUE
	checkitem ITEM_LURE, 1
	goto_if_eq VAR_RESULT, TRUE, EventScript_LureUseAnother
	checkitem ITEM_SUPER_LURE, 1
	goto_if_eq VAR_RESULT, TRUE, EventScript_LureUseAnother
	checkitem ITEM_MAX_LURE, 1
	goto_if_eq VAR_RESULT, TRUE, EventScript_LureUseAnother
.else
	checkitem VAR_LAST_REPEL_LURE_USED, 1
	goto_if_eq VAR_RESULT, TRUE, EventScript_LureUseAnother
.endif
	lock
	msgbox Text_LureWoreOff, MSGBOX_SIGN
	release
	end

EventScript_LureUseAnother:
	lock
	msgbox Text_UseAnotherLure, MSGBOX_YESNO
.if I_REPEL_LURE_MENU == TRUE
	goto_if_eq VAR_RESULT, NO, EventScript_LureWoreOff_End
	callnative TryDrawLureMenu
	goto_if_eq VAR_RESULT, FALSE, EventScript_LureWoreOff_Chose
	waitstate
	goto_if_eq VAR_RESULT, 127, EventScript_LureWoreOff_End
EventScript_LureWoreOff_Chose:
	callnative HandleLureMenuChoice
	bufferitemname 1, VAR_0x8004
	removeitem VAR_0x8004, 1
	playse SE_REPEL
	msgbox Text_UsedNewRepelLure, MSGBOX_SIGN
.else
	goto_if_eq VAR_RESULT, YES, EventScript_UsedLure
.endif
EventScript_LureWoreOff_End:
	release
	end

EventScript_UsedLure:
	bufferitemname 1, VAR_LAST_REPEL_LURE_USED
	playse SE_REPEL
	lock
	msgbox Text_UsedNewRepelLure, MSGBOX_SIGN
	removeitem VAR_LAST_REPEL_LURE_USED, 1
	waitse
	callnative HandleUseExpiredLure
	release
	end

Text_RepelWoreOff:
	.string "Repel's effect wore off…$"

Text_RepelWoreOff_UseAnother:
	.string "Repel's effect wore off…\n"
	.string "Use another?$"

Text_LureWoreOff:
	.string "Lure's effect wore off…$"

Text_UseAnotherLure::
	.string "Lure's effect wore off!\n"
	.string "Use another?$"

Text_UsedNewRepelLure::
	.string "{PLAYER} used the\n"
	.string "{STR_VAR_2}.$"
