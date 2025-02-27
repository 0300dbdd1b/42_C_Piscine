/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noaddino <noaddino@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:43:03 by noaddino          #+#    #+#             */
/*   Updated: 2025/02/25 16:11:14 by noaddino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 1000
# define READ_SIZE 100

typedef struct s_pos
{
	unsigned int	x;
	unsigned int	y;
}	t_pos;

typedef struct s_solution
{
	t_pos	pos;
	int		size;
}	t_solution;

typedef struct s_map
{
	char			empty_char;
	char			obstacle_char;
	char			full_char;
	unsigned int	width;
	unsigned int	height;
	void			*raw_map_ptr;
	char			*raw_map;			// ALLOCATED
	char			*solved_map;		// ALLOCATED
	char			**map;				// ALLOCATED
	unsigned int	first_line_length;
	unsigned char	is_valid;
	t_solution		solution;
}	t_map;

typedef struct s_stand_input
{
	char	*str;
	size_t	allocated;
	size_t	used;
}	t_stand_input;

typedef struct s_user_input
{
	char	*raw_input;
	int		input_size;
}	t_user_input;

/*===============	bsq.c	================*/
int				ft_bsq(t_map *map);

/*===============	map.c	================*/
t_map			*create_map(void);
char			*get_raw_file(char *filepath);
void			get_map_params_from_first_line(t_map *map);
t_map			*get_map(char *filepath);
void			free_map(t_map *map);

/*===============	map-checker.c	================*/
int				check_map_params(t_map *map);
int				check_map_size(t_map *map);
int				check_map_characters(t_map *map);
int				check_map(t_map *map);

/*===============	ft_split.c	================*/
int				is_in_charset(char c, char *charset);
int				count_words(char *str, char *charset);
int				get_word(char **dest, char *str, char *charset);
char			**ft_split(char *str, char *charset);

/*===============	ft_join.c	================*/
int				ft_strslen(int count, char **strs);
char			*ft_strcat(char *dest, char *src);
void			ft_fill_memory(char *memory, int size);
char			*ft_strjoin(int size, char **strs, char *sep);

/*===============	file-utils.c	================*/
unsigned int	get_file_size(char *filepath);
char			*get_raw_file(char *filepath);

/*===============	print-utils.c	================*/
int				is_printable(char c);
void			ft_putstr_fd(char *str, int fd);
void			ft_putnbr_fd(int nb, int fd);
void			print_map_params(t_map *map);

/*===============	square-finder.c	================*/
int				check_empty(t_map *map, t_pos start, t_pos end);
t_solution		find_biggest_square(t_map *map, t_pos coord);
t_solution		ft_find_solution(t_map *map);
void			fill_square(t_map *map, t_solution solution);

/*===============	stdlib-utils.c	================*/
unsigned int	ft_strlen(char *str);
unsigned int	ft_strlen_till_charset(char *str, char *charset);
void			ft_getline(t_stand_input *input);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_realloc(void *ptr, size_t old_size, size_t new_size);
t_stand_input	*input_init(t_stand_input *input);
t_stand_input	*input_realloc(t_stand_input *input);
int				ft_atoin(const char *str, int size);
void			take_input_from_stdin(t_map *map);

#endif
