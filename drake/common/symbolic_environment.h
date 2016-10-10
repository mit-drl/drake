#pragma once

#include <initializer_list>
#include <ostream>
#include <string>
#include <unordered_map>

#include "drake/common/drake_export.h"
#include "drake/common/symbolic_variable.h"

namespace drake {
namespace symbolic {
/** Represent a symbolic form of an environment (mapping from a variable
 * to a value).
 */
class DRAKE_EXPORT Environment {
 public:
  typedef typename drake::symbolic::Variable key_type;
  typedef double mapped_type;
  typedef typename std::unordered_map<key_type, mapped_type> map;
  /** std::pair<key_type, mapped_type> */
  typedef typename map::value_type value_type;
  typedef typename map::iterator iterator;
  typedef typename map::const_iterator const_iterator;

  /** Default constructor. */
  Environment() = default;

  /** Move-construct a set from an rvalue. */
  Environment(Environment&& e) = default;

  /** Copy-construct a set from an lvalue. */
  Environment(const Environment& e) = default;

  /** Move-assign a set from an rvalue. */
  Environment& operator=(Environment&& e) = default;

  /** Copy-assign a set from an lvalue. */
  Environment& operator=(const Environment& e) = default;

  /** List constructor. */
  Environment(std::initializer_list<value_type> init);

  /** Returns an iterator to the beginning. */
  iterator begin() { return map_.begin(); }
  /** Returns an iterator to the end. */
  iterator end() { return map_.end(); }
  /** Returns a const iterator to the beginning. */
  const_iterator begin() const { return map_.cbegin(); }
  /** Returns a const iterator to the end. */
  const_iterator end() const { return map_.cend(); }
  /** Returns a const iterator to the beginning. */
  const_iterator cbegin() const { return map_.cbegin(); }
  /** Returns a const iterator to the end. */
  const_iterator cend() const { return map_.cend(); }

  /** Inserts a pair (\p key, \p elem). */
  void insert(const key_type& key, const mapped_type& elem);
  /** Checks whether the container is empty.  */
  bool empty() const { return map_.empty(); }
  /** Returns the number of elements. */
  size_t size() const { return map_.size(); }

  /** Finds element with specific key. */
  iterator find(const key_type& key) { return map_.find(key); }
  /** Finds element with specific key. */
  const_iterator find(const key_type& key) const { return map_.find(key); }

  /** Returns string representation. */
  std::string to_string() const;

  friend DRAKE_EXPORT std::ostream& operator<<(std::ostream& os,
                                               const Environment& env);

 private:
  map map_;
};
}  // namespace symbolic
}  // namespace drake
