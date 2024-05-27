/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:10:07 by gmastroc          #+#    #+#             */
/*   Updated: 2024/05/27 13:47:40 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
//librerie
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <signal.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <sys/types.h>
# include <errno.h>
# include <get_next_line.h> 
# include <ft_printf.h>

# define BASE16 "0123456789abcdef"
# define BASE16UPPER "0123456789ABCDEF"
# define BASE10 "0123456789"

//		BOX - PROTOTYPES

//get_next_line
// char	*ft_strjoin_free(const char *s1, const char *s2);
// char	*ft_leftover_file(char *selection, char *line);
// char	*ft_defined_line(char *selection);
// char	*ft_read(int fd, char *selection);
// char	*get_next_line(int fd);

//		projects
int		ft_printf(const char *format, ...);

//		basic
/**
 * @brief alfanumerico
 * @param c char
 * @return true or false
 * @bug none
 */
int		ft_isalnum(int c);
/**
 * @brief Alfabeto
 * @param c 
 * @return 
 */
int		ft_isalpha(int c);

int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
/**
 * @brief conversione a int
 * @param str 
 * @bug min int = 0
 * @return result*sign
 */

//		memory 

int		ft_memcmp(const void *s1, const void *s2, size_t n);
/**
 * @brief set memory - specific char
 * @details used in bzero
*/
void	*ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);

//		strings

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlcpy(char *dst, const char *src, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
/**
 * @details recalls memmove funct
*/
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);

//		allocation

char	*ft_itoa(int nbr);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	**ft_split(const char *s, char c);

//		printing

int		ft_atoi(const char *str);
int		ft_putchar_fd(const char s, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putnbr_base(unsigned long n, char *base);
int		ft_putptr(uintptr_t ptr);

#endif
