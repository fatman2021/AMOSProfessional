#ifndef CLIB_NEURALNET_H
#define CLIB_NEURALNET_H
/*
**	$VER: neuralnet_protos.h v5.0 (1.7.99)
**
**	C prototype definitions
*/

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif


/*   public functions:  */

void *NN_CreateA(ULONG input, ULONG hidden, ULONG output, struct TagItem *tags);
void *NN_Create(ULONG input, ULONG hidden, ULONG output, Tag tag1, ...);
void NN_Delete(void *net);
void NN_Reset(void *net);
void NN_Recall(void *net);

void NN_Train(void *net, float *errorptr);

void NN_SetInputLayer(void *net, float *array);
void NN_SetOutputLayer(void *net, float *array);
void NN_GetOutputLayer(void *net, float *array);

BOOL NN_LoadA(void *net, char *filename, struct TagItem *tags);
BOOL NN_Load(void *net, char *filename, Tag tag1, ...);
BOOL NN_SaveA(void *net, char *filename, struct TagItem *tags);
BOOL NN_Save(void *net, char *filename, Tag tag1, ...);

void *NN_Clone(void *net);

#endif
