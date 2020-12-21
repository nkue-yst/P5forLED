all : install
	$(MAKE) -C ./examples/Server
	$(MAKE) -C ./examples/Client

install :
	$(MAKE) install -C ./lib/server/src
	$(MAKE) install -C ./lib/client/src

uninstall :
	$(MAKE) uninstall -C ./lib/server/src
	$(MAKE) uninstall -C ./lib/client/src

clean : uninstall
	$(MAKE) clean -C ./examples/Server
	$(MAKE) clean -C ./examples/Client
	$(MAKE) clean -C ./lib/server/src
	$(MAKE) clean -C ./lib/client/src
