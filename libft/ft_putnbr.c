#include "libft.h"

int	ft_putnbr(int n)
{
	char	number;
	int		count;
	long	nb;

	nb = (long)n;
	count = 0;
	if (nb < 0)
	{
		count += write (1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		count += ft_putnbr(nb / 10);
	number = (nb % 10) + '0';
	count += write (1, &number, 1);
	return (count);
}

static int	ft_unsigned_length(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_putunbr(unsigned int n)
{
	char	c;

	if (n > 9)
		ft_putunbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (ft_unsigned_length(n));
}