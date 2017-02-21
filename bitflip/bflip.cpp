#include <iostream>
#include <string>
#include <vector>

class BitFlipper 
{
	private :

		int		ft_strlen(char *str)
		{
			int		i = -1;

			while (str[++i])
				;
			return (i);
		}

		int		getMin(char *str)
		{
			int		i = -1;

			while (str[++i])
				if (str[i] == '1')
					break;
			return (i);
		}

		int		getMax(char *str)
		{
			int		i = ft_strlen(str);
			
			while (--i >= 0)
				if (str[i] == '1')
					break ;
			return (i);
		}

		int		flip(char **str)
		{
			int		min = getMin(*str);
			int		max = getMax(*str);
			int		i = min;
			int		ret = 0;
			char	*ptr = *str;

			std::cout << "min: " << min << std::endl;
			std::cout << "max: " << max << std::endl;
			while (i <= max)
			{
				if (ptr[i] == '0')
					ptr[i] = '1';
				else if (ptr[i] == '1')
					ptr[i] = '0';
				else
					return (-1);
				++i;
			}
			std::cout << "point: " << ptr << std::endl;
			if (max >= min)
				return (max - min + 1);
			return (0);
		}

		int		resetted(char *str)
		{
			int		i = -1;

			while (str[++i])
				if (str[i] != '0')
					return (1);
			return (0);
		}

	public :

		int		minFlip(char *str)
		{
			int		ret = 0;

			while (resetted(str))
			{
				ret += flip(&str);
				std::cout << str << std::endl;
			}
			return (ret);
		}
};

int		main(int ac, char **av)
{
	BitFlipper	bfl;
	char		*str;

	if (ac == 2)
		std::cout << bfl.minFlip(av[1]) << std::endl;
	else
		std::cout << "Wrong numer of args" << std::endl;
	str = new char [9];
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = 'd';
	str[4] = 'e';
	str[5] = 'f';
	str[6] = 'g';
	str[7] = 'h';
	str[8] = '\0';
	std::cout << str << std::endl;
	delete[] str;
	return (0);
}
