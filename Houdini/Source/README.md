1. Download and install [Visual Studio 2015 Community] (http://bfy.tw/6diT). Pick **custom** install and remember to select C++ tools to be installed.
2. Add environment variable MSVCDir that points to VC directory that you can find inside Visual Studio 15 install directory. Example: E:/VS2015/VC
3. Launch Houdini Command Line Tools.

To compile this, you need to execute command. For this you need some data:
- Path to **VHADCStaticLibrary.lib** file.
- Path to **SOP_Registration.cpp** file.
- Output path where compiled DLL file will be installed. This is optional and is required only if your DSO directory is not placed in default path.

Once you have this data, you need to assemble it in one command, for example:
```
hcustom -l "%GITHUB_PATH%/missingscrolls-lib/Houdini/Source/ThirdParty/StaticLibraries/*.lib" "%GITHUB_PATH%/missingscrolls-lib/Houdini/Source/Operators/SOP_Registration.cpp"
```
or if you use custom DSO path:
```
hcustom -l "%GITHUB_PATH%/missingscrolls-lib/Houdini/Source/ThirdParty/StaticLibraries/*.lib" "%GITHUB_PATH%/missingscrolls-lib/Houdini/Source/Operators/SOP_Registration.cpp" -i "%GITHUB_PATH%/missingscrolls-lib/Houdini/Home/dso"
```

And remember to remove old DLL file, if you still have it under different name there.

Lastly, if you need to compile it for other operating system than Windows, than you need to compile or link to [V-HACD] (https://github.com/nodeway/v-hacd) in your project. Can't help with that, but if you want to do this, I'm sure that you know what you are doing.
