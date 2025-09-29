{
  description = "A quick flake for STM32 development";
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
            # Markdown editing
            harper
            marksman

            # Project development
            kicad
            platformio

            # Git utils
            lazygit
          ];

          shellHook = ''
            echo "You're in the STM32 Project
          '';
        };
    };
}
