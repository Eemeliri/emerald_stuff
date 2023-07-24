CofagrigusSightTile::
    lock
    playmoncry SPECIES_COFAGRIGUS CRY_MODE_NORMAL
    msgbox CofagrigusSeePlayerText, MSGBOX_AUTOCLOSE
    waitmessage
    warpspinenter MAP_VAJRA_PYRAMID_BF1, 36, 34
    release
    end

CofagrigusSeePlayerText::
    .string "Cofff!!$"
