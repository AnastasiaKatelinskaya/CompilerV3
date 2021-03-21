#pragma once

#include "Grammar.h"
#include "GrammarProduction.h"
#include "GrammarProductionFactory.h"

#include <memory>
#include <string>
#include <vector>

class GrammarBuilder
{
public:
	explicit GrammarBuilder(std::unique_ptr<GrammarProductionFactory>&& factory);

	GrammarBuilder& AddProduction(const std::string& line);
	std::unique_ptr<Grammar> Build() const;

private:
	std::vector<std::shared_ptr<GrammarProduction>> m_productions;
	std::unique_ptr<GrammarProductionFactory> m_factory;
};
