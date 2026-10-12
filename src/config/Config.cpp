#include "Config.hpp"

#include <abyssparse.hpp>
#include <cstdlib>
#include <print>

static std::string configPath() {
    const char* xdg  = getenv("XDG_CONFIG_HOME");
    std::string base = xdg ? xdg : (std::string{getenv("HOME")} + "/.config");
    return base + "/abyss-polkit-agent/abyss-polkit-agent.conf";
}

CConfigManager::CConfigManager() : m_path(configPath()) {}

void CConfigManager::load() {
    Abyssparse::SConfigOptions opts;
    opts.allowMissingConfig = true;
    Abyssparse::CConfig cfg{m_path.c_str(), opts};

    cfg.addConfigValue("general:password_field_width", Abyssparse::INT{340});
    cfg.addConfigValue("general:window_width", Abyssparse::INT{520});
    cfg.addConfigValue("general:window_height", Abyssparse::INT{440});
    cfg.addConfigValue("general:show_details", Abyssparse::INT{1});

    cfg.commence();
    const auto res = cfg.parse();
    if (res.error)
        std::print(stderr, "abyss-polkit-agent: config parse error: {}\n", res.getError());

    auto iv = [&](const char* k) { return std::any_cast<Abyssparse::INT>(cfg.getConfigValue(k)); };

    m_cfg.passwordFieldWidth = iv("general:password_field_width");
    m_cfg.windowWidth        = iv("general:window_width");
    m_cfg.windowHeight       = iv("general:window_height");
    m_cfg.showDetails        = iv("general:show_details") != 0;
}
