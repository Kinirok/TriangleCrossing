# TriangleCrossing
# develop-ветка это наш конечный вариант работы, main - там, где работаем. Надеюсь разберемся

# Инструкция по настройке OpenGl:
# 1. Загрузите и разархивируйте glutdlls
# 2. Скопируйте glut.lib в папку 
# C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\VS\lib\x64
# 3. Скопируйте glut32.lib
# C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\VS\lib\x86
# 4. Создайте папку gl, скопируйте туда glut.h и переместите эту папку в
# C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\VS\include
# 5. Скопируйте glut.dll и glut32.dll в папку 
# C:\Windows\System (или C:\Windows\SysWOW64)
# 6. И последнее, скопируйте glut32.dll в папку
# C:\Windows\System32
# Чтобы использовать OpenGl в проекте, подключайте glut.h 
# #include <GL/glut.h>.
