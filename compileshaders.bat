C:/VulkanSDK/1.4.321.1/Bin/glslc.exe shaders/triangle.vert -o vert.spv
C:/VulkanSDK/1.4.321.1/Bin/glslc.exe shaders/triangle.frag -o frag.spv

xcopy vert.spv C:\Users\AnnSe\source\repos\VulkanRenderer\out\build\x64-debug /y
xcopy frag.spv C:\Users\AnnSe\source\repos\VulkanRenderer\out\build\x64-debug /y
pause 