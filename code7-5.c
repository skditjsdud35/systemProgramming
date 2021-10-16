void fork3()
{
	printf("L0\n");
	fork();
	printf("L1\n");
	fork();
	printf("L2\n");
	fork();
	printf("Bye\n");
}
