

//Da una gentile concessione del grande stregone Vincenzoland, colui che si muove non visto con grandi falcate nel vento, il grande sapiente, notevole maestro.



#include "Replacer.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
		return (1);

	Replacer rep(argv[1], argv[2], argv[3]);
	rep.fileReplace();

	return (0);
}