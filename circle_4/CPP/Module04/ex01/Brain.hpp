#ifndef BRAIN_HPP

# define BRAIN_HPP
# include <iostream>
# include <cstring>

class Brain {
private:
	std::string ideas[100];

public:
	Brain();
	~Brain();
	Brain(const Brain &src);
	Brain& operator=(const Brain &src);
	std::string getIdeas(unsigned int i);
	void setIdeas(std::string idea, unsigned int i);
};

#endif