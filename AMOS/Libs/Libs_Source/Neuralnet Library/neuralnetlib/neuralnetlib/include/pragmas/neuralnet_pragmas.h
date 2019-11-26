/*
**   neuralnet_lib.fd
**   v5.0
*/

#pragma libcall NeuralBase NN_CreateA 24 821004
#pragma libcall NeuralBase NN_Delete 2a 801
#pragma libcall NeuralBase NN_Reset 30 801
#pragma libcall NeuralBase NN_Recall 36 801
#pragma libcall NeuralBase NN_SetInputLayer 54 9802
#pragma libcall NeuralBase NN_SetOutputLayer 5a 9802
#pragma libcall NeuralBase NN_GetOutputLayer 60 9802
#pragma libcall NeuralBase NN_Clone 7e 801
#pragma libcall NeuralBase NN_LoadA 84 A9803
#pragma libcall NeuralBase NN_SaveA 8a A9803
#pragma libcall NeuralBase NN_Train 90 9802

#pragma tagcall NeuralBase NN_Create 24 821004
#pragma tagcall NeuralBase NN_Load 84 A9803
#pragma tagcall NeuralBase NN_Save 8a A9803
