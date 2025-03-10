/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperrier <vperrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:19:11 by vperrier          #+#    #+#             */
/*   Updated: 2024/04/30 17:19:13 by vperrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>

typedef struct s_element	t_element;
struct s_element
{
	int			number;
	t_element	*next;
	t_element	*previous;
};

typedef struct s_list		t_list;
struct s_list
{
	int			size;
	t_element	*first;
	t_element	*last;
};

typedef struct s_stacks		t_stacks;
struct s_stacks
{
	int	nb_stacks;
	int	nb_in_stacks;
};

/*instructions*/
void		sa(t_list *list);
void		sb(t_list *list);
void		ss(t_list *list_a, t_list *list_b);
void		ra(t_list *list);
void		rb(t_list *list);
void		rr(t_list *list_a, t_list *list_b);
void		rra(t_list *list);
void		rrb(t_list *list);
void		rrr(t_list *list_a, t_list *list_b);
void		pa(t_list *list_a, t_list *list_b);
void		pb(t_list *list_a, t_list *list_b);

/*algo*/
void		a_in_b(t_list *list_a, t_list *list_b, t_list *stack_limits);
void		algo(t_list *list_a, t_list *list_b,
				t_list *stack, t_stacks *stack_param);
long		the_real_biggest(t_list *list);
int			where_bigest(t_list *list_a, t_list *list_b, long current);
long		the_smallest(t_list *liste, int nombre);
void		push_biggest(t_list *list_a, t_list *list_b, long biggest);
long		biggest_list(t_list *list, long current);
void		suppression_first(t_list *list);
int			check_sort(t_list *list, int size);

/*main*/
int			check_first(int argc, char **argv);
int			check_process(int argc, char **argv, int d, char **li);
int			check_doublons(t_list *list);
int			check_error_imput(int sizelist, char **list);
int			check_error_imput2(char *list);
char		**ft_split(const char *str, char c);
int			check_space(char *list);
void		check_space_multichar(int argc, char **list);

//two_and_five.c
void		two_or_five(t_list *list_a, t_list *list_b);

//power.c
double		power(double base, double exponent);

//three.c
void		three(t_list *list);

//utils.c
void		ft_putchar(char car);
void		ft_putstr(char *li);
size_t		ft_strlen(const char *str);
void		free_all(t_list *list_a, t_list *list_b,
				t_list *stack_limits, t_stacks *stack_param);

//utils_struct.c
t_list		*initialization(void);
t_stacks	*init_stacks(void);
void		insertion(t_list *list, int new_number);
void		suppression(t_list *list);

#endif
