// Auto generated code
#include "remote_call_handler_base.gen.h"
#include "serialization.gen.h"

bool HandleRemoteCall(SocketHandler& socketHandler, RemoteCallHandlerBase& callHandler)
{
    std::vector<uint8_t> buffer_in;
    std::vector<uint8_t> buffer_out;

    if (!socketHandler.Receive(buffer_in))
        return false;

    uint64_t function_id = 0;
    size_t offset = 0;

    if (!Deserialize(&function_id, buffer_in, &offset)) return false;

    bool success = false;

    switch (function_id)
    {
        case (1): // WriteMessageBox
        {
            std::string message;
            if (!Deserialize(&message, buffer_in, &offset))
                return false;

            success = callHandler.WriteMessageBox(message);

            if (!Serialize(success, buffer_out))
                return false;

            break;
        }
        case (2): // GetGameTime
        {
            uint64_t time;

            uint64_t frame;

            success = callHandler.GetGameTime(&time, &frame);

            if (!Serialize(success, buffer_out))
                return false;

            if (!Serialize(time, buffer_out))
                return false;

            if (!Serialize(frame, buffer_out))
                return false;

            break;
        }
        case (3): // GetWorldIslands
        {
            uint32_t area;
            if (!Deserialize(&area, buffer_in, &offset))
                return false;

            bool mustBelongToThePlayer;
            if (!Deserialize(&mustBelongToThePlayer, buffer_in, &offset))
                return false;

            std::vector<IslandInfo> islands;

            success = callHandler.GetWorldIslands(area, mustBelongToThePlayer, &islands);

            if (!Serialize(success, buffer_out))
                return false;

            if (!Serialize(islands, buffer_out))
                return false;

            break;
        }
        case (4): // GetAllAreas
        {
            std::vector<uint32_t> areas;

            success = callHandler.GetAllAreas(&areas);

            if (!Serialize(success, buffer_out))
                return false;

            if (!Serialize(areas, buffer_out))
                return false;

            break;
        }
        case (5): // GetIslandResources
        {
            uint32_t areaCode;
            if (!Deserialize(&areaCode, buffer_in, &offset))
                return false;

            uint32_t islandId;
            if (!Deserialize(&islandId, buffer_in, &offset))
                return false;

            std::vector<IslandResource> resources;

            success = callHandler.GetIslandResources(areaCode, islandId, &resources);

            if (!Serialize(success, buffer_out))
                return false;

            if (!Serialize(resources, buffer_out))
                return false;

            break;
        }
        case (6): // GetIslandResidentialConsumption
        {
            uint32_t areaCode;
            if (!Deserialize(&areaCode, buffer_in, &offset))
                return false;

            uint32_t islandId;
            if (!Deserialize(&islandId, buffer_in, &offset))
                return false;

            std::vector<ResourceConsumption> resources;

            success = callHandler.GetIslandResidentialConsumption(areaCode, islandId, &resources);

            if (!Serialize(success, buffer_out))
                return false;

            if (!Serialize(resources, buffer_out))
                return false;

            break;
        }
        case (7): // GetIslandIndustrialConversion
        {
            uint32_t areaId;
            if (!Deserialize(&areaId, buffer_in, &offset))
                return false;

            uint32_t islandId;
            if (!Deserialize(&islandId, buffer_in, &offset))
                return false;

            std::vector<ResourceConsumption> resources;

            success = callHandler.GetIslandIndustrialConversion(areaId, islandId, &resources);

            if (!Serialize(success, buffer_out))
                return false;

            if (!Serialize(resources, buffer_out))
                return false;

            break;
        }
        case (8): // MinMaxResourcesOnIsland
        {
            uint32_t areaId;
            if (!Deserialize(&areaId, buffer_in, &offset))
                return false;

            uint32_t islandId;
            if (!Deserialize(&islandId, buffer_in, &offset))
                return false;

            uint32_t lowerBound;
            if (!Deserialize(&lowerBound, buffer_in, &offset))
                return false;

            uint32_t upperBound;
            if (!Deserialize(&upperBound, buffer_in, &offset))
                return false;

            success = callHandler.MinMaxResourcesOnIsland(areaId, islandId, lowerBound, upperBound);

            if (!Serialize(success, buffer_out))
                return false;

            break;
        }
        case (9): // DebugGetResourceInfoFromAddress
        {
            uint64_t address;
            if (!Deserialize(&address, buffer_in, &offset))
                return false;

            IslandResource resource;

            success = callHandler.DebugGetResourceInfoFromAddress(address, &resource);

            if (!Serialize(success, buffer_out))
                return false;

            if (!Serialize(resource, buffer_out))
                return false;

            break;
        }
        case (10): // DebugGetResourceChainInfoFromAddress
        {
            uint64_t address;
            if (!Deserialize(&address, buffer_in, &offset))
                return false;

            std::vector<IslandResource> resource;

            success = callHandler.DebugGetResourceChainInfoFromAddress(address, &resource);

            if (!Serialize(success, buffer_out))
                return false;

            if (!Serialize(resource, buffer_out))
                return false;

            break;
        }
        case (11): // DebugGetIslandNameFromAddress
        {
            uint64_t address;
            if (!Deserialize(&address, buffer_in, &offset))
                return false;

            std::string name;

            success = callHandler.DebugGetIslandNameFromAddress(address, &name);

            if (!Serialize(success, buffer_out))
                return false;

            if (!Serialize(name, buffer_out))
                return false;

            break;
        }
        case (12): // DebugReadStringFromAddress
        {
            uint64_t address;
            if (!Deserialize(&address, buffer_in, &offset))
                return false;

            std::string name;

            success = callHandler.DebugReadStringFromAddress(address, &name);

            if (!Serialize(success, buffer_out))
                return false;

            if (!Serialize(name, buffer_out))
                return false;

            break;
        }
        case (13): // DebugGetIslandResources
        {
            uint64_t address;
            if (!Deserialize(&address, buffer_in, &offset))
                return false;

            std::vector<IslandResource> resources;

            success = callHandler.DebugGetIslandResources(address, &resources);

            if (!Serialize(success, buffer_out))
                return false;

            if (!Serialize(resources, buffer_out))
                return false;

            break;
        }
        case (14): // DebugGetIslandChainFromAddress
        {
            uint64_t address;
            if (!Deserialize(&address, buffer_in, &offset))
                return false;

            bool mustBelongToThePlayer;
            if (!Deserialize(&mustBelongToThePlayer, buffer_in, &offset))
                return false;

            std::vector<IslandInfo> islands;

            success = callHandler.DebugGetIslandChainFromAddress(address, mustBelongToThePlayer, &islands);

            if (!Serialize(success, buffer_out))
                return false;

            if (!Serialize(islands, buffer_out))
                return false;

            break;
        }
        case (15): // DebugGetFirstAreaStructAddress
        {
            uint64_t address;

            success = callHandler.DebugGetFirstAreaStructAddress(&address);

            if (!Serialize(success, buffer_out))
                return false;

            if (!Serialize(address, buffer_out))
                return false;

            break;
        }
        case (16): // DebugGetAreaWithCode
        {
            uint32_t code;
            if (!Deserialize(&code, buffer_in, &offset))
                return false;

            uint64_t address;

            success = callHandler.DebugGetAreaWithCode(code, &address);

            if (!Serialize(success, buffer_out))
                return false;

            if (!Serialize(address, buffer_out))
                return false;

            break;
        }
        case (17): // DebugGetNameFromGuid
        {
            uint32_t guid;
            if (!Deserialize(&guid, buffer_in, &offset))
                return false;

            std::string name;

            success = callHandler.DebugGetNameFromGuid(guid, &name);

            if (!Serialize(success, buffer_out))
                return false;

            if (!Serialize(name, buffer_out))
                return false;

            break;
        }
        case (18): // DebugGetGuidFromName
        {
            std::string name;
            if (!Deserialize(&name, buffer_in, &offset))
                return false;

            uint32_t guid;

            success = callHandler.DebugGetGuidFromName(name, &guid);

            if (!Serialize(success, buffer_out))
                return false;

            if (!Serialize(guid, buffer_out))
                return false;

            break;
        }
        case (19): // DebugVirtualGetComponentFromAddress
        {
            uint64_t address;
            if (!Deserialize(&address, buffer_in, &offset))
                return false;

            uint64_t componentId;
            if (!Deserialize(&componentId, buffer_in, &offset))
                return false;

            uint64_t componentAddress;

            success = callHandler.DebugVirtualGetComponentFromAddress(address, componentId, &componentAddress);

            if (!Serialize(success, buffer_out))
                return false;

            if (!Serialize(componentAddress, buffer_out))
                return false;

            break;
        }
        case (20): // DebugGetIslandBuildingAddresses
        {
            uint32_t areaId;
            if (!Deserialize(&areaId, buffer_in, &offset))
                return false;

            uint32_t islandId;
            if (!Deserialize(&islandId, buffer_in, &offset))
                return false;

            std::vector<uint64_t> addresses;

            success = callHandler.DebugGetIslandBuildingAddresses(areaId, islandId, &addresses);

            if (!Serialize(success, buffer_out))
                return false;

            if (!Serialize(addresses, buffer_out))
                return false;

            break;
        }
        case (21): // DebugTryEnqueueShipForTrade
        {
            uint32_t areaId;
            if (!Deserialize(&areaId, buffer_in, &offset))
                return false;

            uint32_t islandId;
            if (!Deserialize(&islandId, buffer_in, &offset))
                return false;

            uint64_t tradeComponent;
            if (!Deserialize(&tradeComponent, buffer_in, &offset))
                return false;

            success = callHandler.DebugTryEnqueueShipForTrade(areaId, islandId, tradeComponent);

            if (!Serialize(success, buffer_out))
                return false;

            break;
        }
    }

    return socketHandler.Send(buffer_out);
}
