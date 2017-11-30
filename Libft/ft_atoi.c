int		ft_atoi(const char *nptr)
{
	int i;
	int nr;
	int sign;

	i = 0;
	nr = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t' ||
		nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nr = nr * 10 + nptr[i] - '0';
		i++;
	}
	return (nr * sign);
}
