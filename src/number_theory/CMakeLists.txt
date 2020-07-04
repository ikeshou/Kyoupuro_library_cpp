# リストとして格納
file(GLOB TEST_SOURCES *.cpp)

foreach(FULL_PATH ${TEST_SOURCES})
    # 拡張子なしファイル名。 /moo/bow/hoge.cpp -> hoge
    get_filename_component(SRC_NAME ${FULL_PATH} NAME_WE)

    # hoge.a にコンパイル
    add_library(${SRC_NAME} STATIC ${FULL_PATH})

    # -I
    target_include_directories(${SRC_NAME}
        PUBLIC
            ${PROJECT_SOURCE_DIR}/include/
        )
endforeach()
