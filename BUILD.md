Изменения для сборки в WebAssembly:

- `clean_cmake.py` - скрипт, очищающий кэш Cmake;
- `empp_throwback.py` - скрипт, очищающий лишние параметры и запускающий em++;
- `extrct_headers.py` - скрипт, собирающий все хедеры в отдельную папку.

Также были внесены изменения в CMakeLists.txt, позволяющие установить параметры сборки с помощью флагов запуска Cmake. Временно закомментирована строка в *WilsonCloudChamber.cpp*, поскольку ее наличие вызывает ошибку исполнения при запуске в вебе.

Инструкция по сборке (MacOS):

1. Установить Emscripten: `brew install emscripten`
2. Запустить Cmake: `cmake -DPLATFORM_WEB=1 -DCMAKE_CXX_COMPILER=$(pwd)/empp_throwback.py -DCMAKE_CXX_COMPILER_WORKS=1 .`
3. Запустить Make: `make`
4. Сохранить результат сборки по пути *phycoub/libphycoub.a*