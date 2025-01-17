/*
 *
 *    Copyright (c) 2024 Project CHIP Authors
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#pragma once

#include <app/clusters/temperature-control-server/supported-temperature-levels-manager.h>
#include <app/util/config.h>

namespace chip {
namespace app {
namespace Clusters {
namespace TemperatureControl {

class AppSupportedTemperatureLevelsDelegate : public SupportedTemperatureLevelsIteratorDelegate
{
    struct EndpointPair
    {
        EndpointId mEndpointId;
        CharSpan * mTemperatureLevels;
        uint8_t mSize;

        EndpointPair(EndpointId aEndpointId, CharSpan * TemperatureLevels, uint8_t size) :
            mEndpointId(aEndpointId), mTemperatureLevels(TemperatureLevels), mSize(size)
        {}
    };

    static CharSpan temperatureLevelOptions[3];
    static const EndpointPair supportedOptionsByEndpoints[MATTER_DM_TEMPERATURE_CONTROL_CLUSTER_SERVER_ENDPOINT_COUNT];

public:
    uint8_t Size() override;

    CHIP_ERROR Next(MutableCharSpan & item) override;

    ~AppSupportedTemperatureLevelsDelegate() {}
};

} // namespace TemperatureControl
} // namespace Clusters
} // namespace app
} // namespace chip
