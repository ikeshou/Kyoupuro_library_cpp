find_package(GTest REQUIRED)
include(GoogleTest)

# リストとして格納
file(GLOB TEST_SOURCES *.cpp)
# ctest のラベル用の変数。現在のディレクトリ名を取得して CURRENT_DIR_NAME に代入
get_filename_component(CURRENT_DIR_NAME ${CMAKE_CURRENT_LIST_DIR} NAME_WE)


foreach(FULL_PATH ${TEST_SOURCES})

    # 拡張子なしファイル名。 /moo/bow/test_hoge.cpp -> test_hoge
    get_filename_component(TEST_NAME ${FULL_PATH} NAME_WE)
    # テスト対象の名前。 test_hoge -> hoge
    set(SUFFIX_NAME "")
    string(REPLACE "test_" "" SUFFIX_NAME ${TEST_NAME})

    # test_hoge.cpp から test_hoge 実行ファイルを作成しようとする
    add_executable(${TEST_NAME} ${FULL_PATH})
    target_compile_options(${TEST_NAME} PRIVATE -Wall)
    target_compile_features(${TEST_NAME} PRIVATE cxx_std_17)
    # -I
    target_include_directories(${TEST_NAME}
        PRIVATE
            /usr/local/include/
            ${PROJECT_SOURCE_DIR}/include/
        )
    # -L
    target_link_directories(${TEST_NAME}
        PRIVATE
            /usr/local/lib/
        )
    # -l
    target_link_libraries(${TEST_NAME}
            ${SUFFIX_NAME}
            randint
            GTest::GTest
            GTest::Main
        )
    
    # ctest へテストの追加。CURRENT_DIR_NAME なるラベルでテストケースを識別できるようにする
    # ビルド後に ctest -L label_name で特定のテストケースのみのテストが行える！
    gtest_add_tests(TARGET ${TEST_NAME} TEST_LIST tmp)
    set_tests_properties(${tmp} PROPERTIES LABELS ${CURRENT_DIR_NAME})

endforeach()

