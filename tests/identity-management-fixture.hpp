/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2014-2016,  Regents of the University of California,
 *                           Arizona Board of Regents,
 *                           Colorado State University,
 *                           University Pierre & Marie Curie, Sorbonne University,
 *                           Washington University in St. Louis,
 *                           Beijing Institute of Technology,
 *                           The University of Memphis.
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

#ifndef NFD_TESTS_IDENTITY_MANAGEMENT_FIXTURE_HPP
#define NFD_TESTS_IDENTITY_MANAGEMENT_FIXTURE_HPP

#include "tests/test-common.hpp"
#include <ndn-cxx/security/key-chain.hpp>
#include <vector>

#include "boost-test.hpp"

namespace nfd {
namespace tests {

/**
 * @brief IdentityManagementFixture is a test suite level fixture.
 *
 * Test cases in the suite can use this fixture to create identities.
 * Identities added via addIdentity method are automatically deleted
 * during test teardown.
 */
class IdentityManagementFixture : public virtual BaseFixture
{
public:
  IdentityManagementFixture();

  ~IdentityManagementFixture();

  // @brief add identity, return true if succeed.
  bool
  addIdentity(const ndn::Name& identity,
              const ndn::KeyParams& params = ndn::KeyChain::DEFAULT_KEY_PARAMS);

protected:
  ndn::KeyChain m_keyChain;
  std::vector<ndn::Name> m_identities;
};

class IdentityManagementTimeFixture : public UnitTestTimeFixture
                                    , public IdentityManagementFixture
{
};

} // namespace tests
} // namespace nfd

#endif // NFD_TESTS_IDENTITY_MANAGEMENT_FIXTURE_HPP
