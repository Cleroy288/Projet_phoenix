void	ft_write_number(int number)
{
	if (number > 9)
		ft_write_number(number / 10);
	write(1, &"0123456789"[number % 10], 1);
}

int	main(void)
{
	int	number;

	number = 1;
	while (number <= 100)
	{
		if (number % 3 == 0 && number % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (number % 3 == 0)
			write(1, "fizz", 4);
		else if (number % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_write_number(number);
		write(1, "\n", 1);
		number++;
	}
}

La syntaxe générale est la suivante : write(descripteur, buffer, count).

descripteur : est un entier entre 0 et 2 qui représente le descripteur de fichier standard. 0 est pour l'entrée 
standard (stdin), 1 est pour la sortie standard (stdout), et 2 est pour l'erreur standard (stderr).
buffer : est un pointeur vers les données à écrire.
count : est la taille en octets des données à écrire.
Dans le code ci-dessus, &"0123456789"[number % 10] est une expression qui renvoie le caractère correspondant à l'unité 
de number % 10. Par exemple, si number est 42, alors number % 10 vaut 2, et donc &"0123456789"[number % 10] renvoie 
le caractère '2'.

Enfin, write (1, &"0123456789"[number % 10], 1) écrit ce caractère sur la sortie standard, c'est-à-dire sur le terminal.
