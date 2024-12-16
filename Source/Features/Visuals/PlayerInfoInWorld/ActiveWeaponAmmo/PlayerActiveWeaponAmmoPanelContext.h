#pragma once

#include <Features/Visuals/PlayerInfoInWorld/PlayerInfoPanelCacheEntry.h>

template <typename HookContext>
class PlayerActiveWeaponAmmoPanelContext {
public:
    PlayerActiveWeaponAmmoPanelContext(HookContext& hookContext, cs2::CUIPanel* panel, PlayerInfoPanelCacheEntry& cache) noexcept
        : _hookContext{hookContext}
        , _panel{panel}
        , _cache{cache}
    {
    }

    [[nodiscard]] auto& state() const noexcept
    {
        return _hookContext.featuresStates().visualFeaturesStates.playerInfoInWorldState;
    }

    [[nodiscard]] bool shouldShowOn(auto&& playerPawn) const noexcept
    {
        return state().showPlayerActiveWeaponAmmo && playerPawn.getActiveWeapon().clipAmmo().greaterThan(-1).valueOr(true);
    }

    [[nodiscard]] decltype(auto) panel() const noexcept
    {
        return _hookContext.template make<PanoramaUiPanel>(_panel);
    }

    [[nodiscard]] auto& cache() const noexcept
    {
        return _cache;
    }

private:
    HookContext& _hookContext;
    cs2::CUIPanel* _panel;
    PlayerInfoPanelCacheEntry& _cache;
};
