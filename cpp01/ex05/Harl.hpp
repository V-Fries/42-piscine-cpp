#include <string>

class Harl
{
public:
	Harl(const std::string& debugMessage, const std::string& infoMessage,
		 const std::string& warningMessage, const std::string& errorMessage);

	void complain(std::string level);

private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

	static int getLevelIndex(std::string& level);


	static const char*	_levels[];

	const std::string	_debugMessage;
	const std::string	_infoMessage;
	const std::string	_warningMessage;
	const std::string	_errorMessage;

	void	(Harl::*_levelFunctions[4])(void);
};
