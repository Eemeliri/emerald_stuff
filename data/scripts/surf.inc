EventScript_UseSurf::
	checkpartymove MOVE_SURF
	goto_if_eq VAR_RESULT, PARTY_SIZE, CheckLearnSurf
CanLearnSurf::
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	lockall
	msgbox gText_WantToUseSurf, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_ReleaseUseSurf
	msgbox gText_PlayerUsedSurf, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_SURF
EventScript_ReleaseUseSurf::
	releaseall
EventScript_EndUseSurf::
	end

CheckLearnSurf::
	canlearntm ITEM_HM03
	goto_if_ne VAR_RESULT, PARTY_SIZE, CanLearnSurf
	end
