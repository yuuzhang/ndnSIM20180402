/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2014,  Regents of the University of California,
 *                      Arizona Board of Regents,
 *                      Colorado State University,
 *                      University Pierre & Marie Curie, Sorbonne University,
 *                      Washington University in St. Louis,
 *                      Beijing Institute of Technology,
 *                      The University of Memphis
 *
 * This file is part of NFD (Named Data Networking Forwarding Daemon).
 * See AUTHORS.md for complete list of NFD authors and contributors.
 *
 * NFD is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * NFD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * NFD, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NDNSIM_EXAMPLES_NDN_RANDOMIZED_ROUNDING_STRATEGY_HPP
#define NDNSIM_EXAMPLES_NDN_RANDOMIZED_ROUNDING_STRATEGY_HPP

#include <boost/random.hpp>
#include <boost/random/mersenne_twister.hpp>
#include "face/face.hpp"
#include "strategy.hpp"
#include "algorithm.hpp"

namespace nfd {
namespace fw {

class RandomizedRoundingStrategy : public Strategy {
public:
  explicit
  RandomizedRoundingStrategy(Forwarder& forwarder, const Name& name = getStrategyName());

  virtual ~RandomizedRoundingStrategy() override;

  virtual void
  afterReceiveInterest(const Face& inFace, const Interest& interest,
                       const shared_ptr<pit::Entry>& pitEntry) override;

  static const Name&
  getStrategyName();

protected:
  boost::random::mt19937 m_randomGenerator;
};

} // namespace fw
} // namespace nfd

#endif // NDNSIM_EXAMPLES_NDN_RANDOMIZED_ROUNDING_STRATEGY_HPP