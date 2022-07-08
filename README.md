# ccomixmanager
Questo vuole essere un proof of concept e probabilmente non verrà mai finito. Vuole dimostrare che meson si basa su pkg-config e snap ha il plugin per meson, quindi dovunque vada pkg-config può andare anche snap.

Per installarlo è necessario avere le librerie gtk e le librerie mariadb da apt, non da snap-store.

E' necessario prendere il database dal mio progetto comixmanager su github e ripristinare il backup (https://github.com/numerunix/ComixManager/tree/master/Dump20190226).

Attualmente sono pesenti solo 3 form di inserimento: editore, fornitore e negozio.

# Installazione
# Debian
sudo add-apt-repository "http://MIO_INDIRIZZO_IP/repos/apt/debian bullseye main"

sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 9D4AE50D

sudo apt install ccomixmanager

# The OLD FASCION DEBIAN WAY
Per installare i package Deb disponibili nella sezione release, bisogna usare dpkg passando come parametro i e i nomi dei files da installare.
Verosimilmente

# cd Scaricati

# sudo dpkg -i *.deb

A questo punto bisogna scaricare le librerie wxwidgets necessarie per l'esecuzione

# sudo apt -f install

I package sono universali e vanno bene sia per Ubuntu che per debian.
Sentitevi liberi di incorporarli nei vostri server apt, a patto di mantenere integro il binario, come prevede la licenza GPL.

[![Scarica dallo Snap Store](https://snapcraft.io/static/images/badges/it/snap-store-black.svg)](https://snapcraft.io/ccomixmanager)

# Donazioni

[![paypal](https://www.paypalobjects.com/it_IT/IT/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=H4ZHTFRCETWXG)

oppure puoi fare una donazione tramite carta hype.

