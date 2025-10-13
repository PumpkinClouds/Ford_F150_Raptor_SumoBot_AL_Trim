{
  description = "A flake for STM32 development";
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-25.05";
  };

  outputs =
    inputs@{ self, nixpkgs, ... }:
    let
      system = "x86_64-linux";
    in
    {
      devShells."${system}".default =
        let
          pkgs = import nixpkgs {
            inherit system;
          };
        in
        pkgs.mkShell {
          packages = with pkgs; [
            clang-tools
            clang
            gcc
            platformio
            python3
            python3Packages.pip

            # Markdown editing
            harper
            marksman
            yaml-language-server

            # Project development
            kicad

            # Git utils
            lazygit
            gitui
          ];

          shellHook = ''
            export PLATFORMIO_CORE_DIR=$PWD/Software/.platformio
            echo "You're in the development shell for the Ford Raptor SumoBot"
          '';
        };
    };
}
