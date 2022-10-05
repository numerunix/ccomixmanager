project('ccomixmanager', 'c', version: '0.3')
gtk_dep = dependency('gtk+-3.0', version : '>=3.0', required : true)
mariadb_dep = dependency('mariadb', required: true)
libnotify_dep=dependency('libnotify', required: true)
executable('ccomixmanager', ['FrameArticolo.c','FrameCategoria.c','FrameClienti.c', 'FrameCollana.c', 'FrameConnessione.c', 'FrameDipendente.c', 'FrameEditore.c', 'FrameFornitore.c', 'FrameNegozio.c', 'FrameOggetto.c', 'main.c'], dependencies : [gtk_dep, mariadb_dep, libnotify_dep], install: true, install_dir: '/usr/bin')

install_data('ccomixmanager.desktop', install_dir: '/usr/share/applications')
