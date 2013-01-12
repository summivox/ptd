# Pocket Tanks Decoder

[Pocket Tanks][pt] is a 2-player artillery game featuring a huge number of weapons which come in [Expansion Packs][pt-depot]. However, an official weapons editor is not available, and the weapon definition file `*.wea` is encrypted. Without means to decrypt and re-encrypt the weapons file, weapon modding is not possible.

This simple tool encrypts/decrypts the weapon definition files `*.wea`, `*.weap`, as well as emitter definition files `*.emi` and `*.emit`. The algorithm is simple and symmetric. See source for details.

I hope this tool could help the game regain some popularity. Enjoy modding!

## Usage

1. Enter directory where `pockettanks.exe` is located
*  Clone this repo
*  Use the `.bat` files
*  results are in `weapdata` directory

If the binary doesn't work, build it yourself with `gcc`.

Tested with Pocket Tanks Deluxe v1.6

## Licence

This tool is released under [WTFPL][] "as-is" with no responsibility assumed; visit the [Official Pocket Tanks Website][pt] for information regarding the game.

The author of this tool is in no way related to Blitwise Productions LLC.

 [pt]: http://www.blitwise.com/ptanks.html
 [pt-depot]: http://www.blitwise.com/ptanksdepot.html
 [WTFPL]: http://www.wtfpl.net/
