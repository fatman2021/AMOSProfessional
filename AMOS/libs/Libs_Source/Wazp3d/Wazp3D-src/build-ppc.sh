echo "Building Wazp3D for PPC ..."
echo "Wazp3D_lib_ppc.c ..."
gcc -D WAZP3DDEBUG -D MOTOROLAORDER -noixemul -O0 -nostartfiles -c Wazp3D_lib_ppc.c  
echo "Wazp3D50.c ..."
gcc -D WAZP3DDEBUG -D MOTOROLAORDER -noixemul -O3 -nostartfiles -c Wazp3D50.c    
echo "linking ..."
gcc -noixemul -nostartfiles -o Warp3D.library-ppc Wazp3D_lib_ppc.o Wazp3D50.o   
echo "Warp3D.library-ppc done..."
echo "Wazp3D-Prefs50.c ..."
gcc -noixemul -c Wazp3D-Prefs50.c  
gcc -noixemul -o Wazp3D-Prefs-ppc Wazp3D-Prefs50.o  
echo "Wazp3D-Prefs-ppc also done..."
echo "CoW3D-2.c ..."
gcc -noixemul -O3 -c CoW3D-2.c
gcc -noixemul -O3 -o CoW3D-2-ppc CoW3D-2.o
echo "CoW3D-2-ppc also done..."