
Add submodule to the `qmk_firmware` repo:
```
git submodule add https://github.com/kiirogami/qmk_sofle.git keyboards/sofle/keymaps/kiiro
```

Compile/flash the layout:
```
qmk compile -kb sofle/rev1 -km kiiro
qmk flash -kb sofle/rev1 -km kiiro
```
