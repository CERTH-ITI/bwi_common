#pragma once

#include <actasp/PartialPolicy.h>

#include <actasp/asp/AspFluent.h>
#include <actasp/state_utils.h>

#include <map>
#include <set>
#include <list>

namespace actasp {
  
struct GraphPolicy : public PartialPolicy {
public:
  
  GraphPolicy(const std::set<std::string>& actions);
  
  ActionSet actions(const std::set<AspFluent>& state) const noexcept;

  void merge(const Plan &plan);
  
  void merge(const PartialPolicy* otherPolicy);
  
  void merge(const GraphPolicy* otherPolicy);
  
  bool empty() const noexcept;
  
  std::vector<actasp::AnswerSet> plansFrom(const std::set<AspFluent>& state) noexcept;
  
private:
  
  typedef std::map<std::set<AspFluent>, ActionSet, StateComparator<AspFluent> >  PolicyMap;
  typedef std::list< std::list< AspFluent> > PlanList; 
  typedef std::list< std::pair< PlanList::const_iterator, std::list< AspFluent>::const_iterator> > PlanReference;
  typedef std::map<std::set<AspFluent>, PlanReference , StateComparator<AspFluent> > PlanIndex;
  
  PolicyMap policy;
  std::set<std::string> allActions;
  PlanList plans;
  PlanIndex planIndex;
  
};
  
}


