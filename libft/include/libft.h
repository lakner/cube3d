/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 01:33:45 by dcharala          #+#    #+#             */
/*   Updated: 2023/02/12 14:04:17 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifdef __linux__
#  include <sys/stat.h>
#  include <fcntl.h>
#  include <unistd.h>
#  include <stdio.h>
#  include <stdlib.h>
#  include <limits.h>
#  include <stddef.h>
#  include <stdint.h>
#  include <stdarg.h>
#  ifndef OS_FLAG
#   define OS_FLAG 'L'
#  endif
# elif __APPLE__
#  include <fcntl.h>
#  include <stdio.h>
#  include <stdlib.h>
#  include <sys/types.h>
#  include <sys/uio.h>
#  include <unistd.h>
#  include <limits.h>
#  include <stdint.h>
#  include <stdarg.h>
#  ifndef OS_FLAG
#   define OS_FLAG 'A'
#  endif
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

# if BUFFER_SIZE > INT_MAX - 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

/* libft */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split(const char *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strncpy(char *src, unsigned int n);

/* get_next_line */
char	*get_next_line(int fd);

/* ft_printf | ft_printf.c */
int		ft_printf(const char *fmt, ...);
void	pf_get_specifiers(va_list ap, char *fmt, int *nbytes);
int		pf_distribute_conversion(char specifier, va_list ap);

/* ft_printf | pf_convert_chr.c */
int		pf_convert_chr(va_list ap);

/* ft_printf | pf_convert_str.c */
int		pf_convert_str(va_list ap);

/* ft_printf | pf_convert_nbr.c */
int		pf_convert_nbr(va_list ap, char specifier);
int		pf_get_nbr_len(long int n);
void	pf_putnbr(long int n);

/* ft_printf | pf_convert_hex.c */
int		pf_convert_hex(va_list ap, char specifier);
int		pf_convert_ptr(va_list ap);
int		pf_get_hex_len(unsigned long long n);
void	pf_puthex(unsigned long long n, char specifier);

#endif
