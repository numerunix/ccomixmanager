project('ccomixmanager', 'c', version: '0.1.2')
gtk_dep = dependency('gtk+-3.0', version : '>=3.0', required : true)
mariadb_dep = dependency('mariadb', required: true)
executable('ccomixmanager', ['articolo.c','categoria.c','cliente.c', 'collana.c', 'dipendente.c', 'editore.c', 'editoreDAO.c', 'fornitore.c', 'fornitoreDAO.c', 'FrameConnessione.c', 'FrameEditore.c', 'FrameFornitore.c', 'FrameNegozio.c', 'helper.c', 'main.c', 'negozio.c', 'negozioDAO.c', 'oggetto.c'], dependencies : [gtk_dep, mariadb_dep], install: true, install_dir: '/usr/bin')

install_data('ccomixmanager.desktop', install_dir: '/usr/share/applications')
