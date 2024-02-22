@setx CE_INCL "%CD%\CURLY-EUREKA-INCL.cmake"
@msg "%username%" CE_INCL NOW: ^

"%CE_INCL%" ^

^

But still recomended to reload ur PC, that env stuff works ugly... ^

^

Then you can add ' include($ENV{CE_INCL}) ' ^

in your CMakeLists.txt in mod project to include curly-eureka :T