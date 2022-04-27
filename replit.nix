{ pkgs }: {
	deps = [
		pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
		pkgs.vim
		pkgs.zip
		pkgs.unzip
		pkgs.dos2unix
		pkgs.rename
	];
}
