echo "Building Wazp3D for 68020-40 ..."
echo "Wazp3D_lib.c ..."
gcc -D WAZP3DDEBUG -D MOTOROLAORDER -m68020-40 -m68881 -noixemul -O0 -nostartfiles -c Wazp3D_lib.c  
echo "Wazp3D50.c ..."
gcc -D WAZP3DDEBUG -D MOTOROLAORDER -m68020-40 -m68881 -noixemul -O2 -nostartfiles -c Wazp3D50.c  
echo "linking ..."
gcc -noixemul -nostartfiles -o Warp3D.library-full Wazp3D_lib.o Wazp3D50.o   
echo "Warp3D.library-full done..."

echo "Wazp3D_lib.c ..."
gcc -D WAZP3DDEBUG -D MOTOROLAORDER -D SOFT3DLIB  -m68020-40 -m68881 -noixemul -O0 -nostartfiles -c Wazp3D_lib.c   
echo "Wazp3D50.c ..."
gcc -D WAZP3DDEBUG -D MOTOROLAORDER -D SOFT3DLIB  -m68020-40 -m68881 -noixemul -O2 -nostartfiles -c Wazp3D50.c    
echo "linking ..."
gcc -noixemul -nostartfiles -o Warp3D.library-winuae Wazp3D_lib.o Wazp3D50.o 
echo "Warp3D.library-winuae done..."

echo "soft3d_lib.c ..."
gcc -D WAZP3DDEBUG -D MOTOROLAORDER -D SOFT3DLIB -D SOFT3DDLL  -m68020-40 -m68881 -noixemul -O0 -nostartfiles -c soft3d_lib.c  
echo "soft3d50.c ..."
gcc -D WAZP3DDEBUG -D MOTOROLAORDER -D SOFT3DLIB -D SOFT3DDLL  -m68020-40 -m68881 -noixemul -O2 -nostartfiles -c soft3d50.c    
echo "linking ..."
gcc -noixemul -nostartfiles -o soft3d.library soft3d_lib.o soft3d50.o        
echo "soft3d.library done..."

echo "All libraries done..."

echo "Wazp3D-Prefs50.c ..."
gcc -noixemul -c Wazp3D-Prefs50.c  Wazp3D-Prefs50.o
gcc -noixemul -o Wazp3D-Prefs Wazp3D-Prefs50.o  
echo "Wazp3D-Prefs also done..."

echo "CoW3D-2.c ..."
gcc -m68020-40 -m68881 -noixemul -O2 -c CoW3D-2.c
gcc -m68020-40 -m68881 -noixemul -O2 -o CoW3D-2 CoW3D-2.c
echo "CoW3D-2 also done..."



