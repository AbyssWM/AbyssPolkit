#pragma once

#include <abyssutils/memory/SharedPtr.hpp>
#include <abyssutils/memory/UniquePtr.hpp>

#include <abysstoolkit/core/Backend.hpp>

#include <memory>
#include <string>

#include "PolkitListener.hpp"

class CDialog;

class CAgent {
  public:
    CAgent();
    ~CAgent();

    bool                                                     start();
    void                                                     beginAuth(CPolkitListener::SAuthRequest req);
    void                                                     endAuth();
    void                                                     onRequest(const std::string& prompt, bool echo);
    void                                                     onInfo(const std::string& text);
    void                                                     onError(const std::string& text);
    void                                                     submitPassword(const std::string& password);
    void                                                     cancel();
    void                                                     selectIdentity(const std::string& identityString);

    Abyssutils::Memory::CSharedPointer<Abysstoolkit::IBackend> backend() {
        return m_backend;
    }

    CPolkitListener& listener() {
        return m_listener;
    }

  private:
    Abyssutils::Memory::CSharedPointer<Abysstoolkit::IBackend> m_backend;

    CPolkitListener                                          m_listener;

    Abyssutils::Memory::CUniquePointer<CDialog>               m_dialog;
    // dialogs waiting for the next idle to be closed and freed, see endAuth
    std::vector<Abyssutils::Memory::CUniquePointer<CDialog>> m_closedDialogs;
};

inline std::unique_ptr<CAgent> g_pAgent;
