#!/bin/bash
#
# test various error cases.

echo ""
echo ""
echo "Test: Execute cub3D with too many arguments."
echo ""
echo "$ ./cub3D arg1 arg2"
echo "---"
./cub3D arg1 arg2
echo ""
read -p "Press enter to continue"

echo ""
echo ""
echo "Test: Execute cub3D with too few arguments."
echo ""
echo "$ ./cub3D "
echo "---"
./cub3D
echo ""
read -p "Press enter to continue"

echo ""
echo ""
echo "Test: The map file does not exist."
echo ""
echo "$ ./cub3D maps/not_exist.cub"
echo "---"
./cub3D maps/not_exist.cub
echo ""
read -p "Press enter to continue"

echo ""
echo ""
echo "Test: The map file has invalid extension."
echo ""
echo "$ ./cub3D maps/test.invalid"
echo "---"
./cub3D maps/test.invalid
echo ""
read -p "Press enter to continue"

echo ""
echo ""
echo "Test: One or more identifiers have invalid arguments."
echo ""
echo "$ ./cub3D maps/errors/texture_path_missing.cub"
echo "---"
cat maps/errors/texture_path_missing.cub
echo ""
./cub3D maps/errors/texture_path_missing.cub
echo ""
read -p "Press enter to continue"

echo ""
echo ""
echo "Test: One or more identifiers are missing."
echo ""
echo "$ ./cub3D maps/errors/mapfile_id_missing.cub"
echo "---"
cat maps/errors/mapfile_id_missing.cub
echo ""
./cub3D maps/errors/mapfile_id_missing.cub
echo ""
read -p "Press enter to continue"

echo ""
echo ""
echo "Test: Invalid identifier."
echo ""
echo "$ ./cub3D maps/errors/mapfile_id_invalid.cub"
echo "---"
cat maps/errors/mapfile_id_invalid.cub
echo ""
./cub3D maps/errors/mapfile_id_invalid.cub
echo ""
read -p "Press enter to continue"

echo ""
echo ""
echo "Test: Duplicated identifier."
echo ""
echo "$ ./cub3D maps/errors/mapfile_id_duplicate.cub"
echo "---"
cat maps/errors/mapfile_id_duplicate.cub
echo ""
./cub3D maps/errors/mapfile_id_duplicate.cub
echo ""
read -p "Press enter to continue"

echo ""
echo ""
echo "Test: No map in the map file."
echo ""
echo "$ ./cub3D maps/errors/mapfile_no_map.cub"
echo "---"
cat maps/errors/mapfile_no_map.cub
echo ""
./cub3D maps/errors/mapfile_no_map.cub
echo ""
read -p "Press enter to continue"

echo ""
echo ""
echo "Test: Could not open texture file."
echo ""
echo "$ ./cub3D maps/errors/texture_path_wrong.cub"
echo "---"
cat maps/errors/texture_path_wrong.cub
echo ""
./cub3D maps/errors/texture_path_wrong.cub
echo ""
read -p "Press enter to continue"


echo ""
echo ""
echo "Test: No read permission."
echo ""
echo "$ ./cub3D maps/errors/texture_path_permission.cub"
echo "---"
cat maps/errors/texture_path_permission.cub
echo ""
chmod -r textures/tux_no_perm.png
./cub3D maps/errors/texture_path_permission.cub
chmod +r textures/tux_no_perm.png
echo ""
read -p "Press enter to continue"

echo ""
echo ""
echo "Test: Check for non-PNG textures."
echo ""
echo "$ ./cub3D maps/errors/texture_png_only.cub"
echo "---"
cat maps/errors/texture_png_only.cub
echo ""
./cub3D maps/errors/texture_png_only.cub
echo ""
read -p "Press enter to continue"

echo ""
echo ""
echo "Test: Invalid color syntax."
echo ""
echo "$ ./cub3D maps/errors/color_invalid_delimiter.cub"
echo "---"
cat maps/errors/color_invalid_delimiter.cub
echo ""
./cub3D maps/errors/color_invalid_delimiter.cub
echo ""
read -p "Press enter to continue"

echo ""
echo ""
echo "Test: Invalid RGB value."
echo ""
echo "$ ./cub3D maps/errors/color_invalid_rgb_value.cub"
echo "---"
cat maps/errors/color_invalid_rgb_value.cub
echo ""
./cub3D maps/errors/color_invalid_rgb_value.cub
echo ""
read -p "Press enter to continue"

echo ""
echo ""
echo "Test: Invalid map borders."
echo ""
echo "$ ./cub3D maps/errors/map_open_border.cub"
echo "---"
cat maps/errors/map_open_border.cub
echo ""
./cub3D maps/errors/map_open_border.cub
echo ""
read -p "Press enter to continue"

echo ""
echo ""
echo "Test: Invalid character on the map."
echo ""
echo "$ ./cub3D maps/errors/map_invalid_character.cub"
echo "---"
cat maps/errors/map_invalid_character.cub
echo ""
./cub3D maps/errors/map_invalid_character.cub
echo ""
read -p "Press enter to continue"

echo ""
echo ""
echo "Test: No player found."
echo ""
echo "$ ./cub3D maps/errors/map_no_player.cub"
echo "---"
cat maps/errors/map_no_player.cub
echo ""
./cub3D maps/errors/map_no_player.cub
echo ""
read -p "Press enter to continue"

echo ""
echo ""
echo "Test: More than one player on the map"
echo ""
echo "$ ./cub3D maps/errors/map_too_many_players.cub"
echo "---"
cat maps/errors/map_too_many_players.cub
echo ""
./cub3D maps/errors/map_too_many_players.cub
echo ""
read -p "Press enter to continue"

echo ""
echo ""
echo "Test: Empty line through the map"
echo ""
echo "$ ./cub3D maps/errors/map_empty_line.cub"
echo "---"
cat maps/errors/map_empty_line.cub
echo ""
./cub3D maps/errors/map_empty_line.cub
echo ""
read -p "Press enter to continue"
