get_target_property(PHY_COUB_INCLUDE_DIRECTORIES phycoub INCLUDE_DIRECTORIES)
get_target_property(WIDGETS_INCLUDE_DIRECTORIES widgets INCLUDE_DIRECTORIES)

include_directories(
        ${PHY_COUB_INCLUDE_DIRECTORIES}
        ${WIDGETS_INCLUDE_DIRECTORIES}
)

add_subdirectory(electroninhomogeneousfields)
add_subdirectory(magnetron)
add_subdirectory(wilsoncloudchamber)