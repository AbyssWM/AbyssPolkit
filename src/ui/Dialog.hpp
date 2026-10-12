#pragma once

#include <abyssutils/memory/SharedPtr.hpp>
#include <abyssutils/signal/Signal.hpp>

#include <abysstoolkit/core/Backend.hpp>
#include <abysstoolkit/window/Window.hpp>
#include <abysstoolkit/element/Textbox.hpp>
#include <abysstoolkit/element/Button.hpp>
#include <abysstoolkit/element/Text.hpp>
#include <abysstoolkit/element/Element.hpp>

#include <string>

#include "../core/PolkitListener.hpp"

class CDialog {
  public:
    CDialog(const CPolkitListener::SAuthRequest& req, Abyssutils::Memory::CSharedPointer<Abysstoolkit::IBackend> backend);
    ~CDialog();

    void show();
    void close();

    void setPrompt(const std::string& text, bool echo);
    void setInfo(const std::string& text);
    void setError(const std::string& text);

  private:
    void                                                            build();
    void                                                            buildPasswordField();
    void                                                            showStatus(Abyssutils::Memory::CSharedPointer<Abysstoolkit::IElement>& wrap, bool& shown, bool show);
    void                                                            showPasswordField(bool show);

    Abyssutils::Memory::CSharedPointer<Abysstoolkit::IBackend>        m_backend;
    Abyssutils::Memory::CSharedPointer<Abysstoolkit::IWindow>         m_window;

    Abyssutils::Memory::CSharedPointer<Abysstoolkit::CTextboxElement> m_passwordField;
    Abyssutils::Memory::CSharedPointer<Abysstoolkit::CTextElement>    m_errorLabel;
    Abyssutils::Memory::CSharedPointer<Abysstoolkit::CTextElement>    m_infoLabel;
    Abyssutils::Memory::CSharedPointer<Abysstoolkit::CTextElement>    m_capsLockLabel;
    Abyssutils::Memory::CSharedPointer<Abysstoolkit::CButtonElement>  m_authButton;
    Abyssutils::Memory::CSharedPointer<Abysstoolkit::CButtonElement>  m_detailsButton;
    Abyssutils::Memory::CSharedPointer<Abysstoolkit::IElement>        m_detailsContainer;
    Abyssutils::Memory::CSharedPointer<Abysstoolkit::IElement>        m_detailsParent;
    Abyssutils::Memory::CSharedPointer<Abysstoolkit::IElement>        m_statusContainer;
    Abyssutils::Memory::CSharedPointer<Abysstoolkit::IElement>        m_capsWrap;
    Abyssutils::Memory::CSharedPointer<Abysstoolkit::IElement>        m_errWrap;
    Abyssutils::Memory::CSharedPointer<Abysstoolkit::IElement>        m_infoWrap;
    Abyssutils::Memory::CSharedPointer<Abysstoolkit::IElement>        m_passwordWrap;
    Abyssutils::Memory::CSharedPointer<Abysstoolkit::IElement>        m_btnRow;

    Abyssutils::Signal::CAbyssSignalListener                          m_closeListener;
    Abyssutils::Signal::CAbyssSignalListener                          m_keyListener;

    CPolkitListener::SAuthRequest                                   m_req;
    std::string                                                     m_currentPassword;
    bool                                                            m_promptEcho     = false;
    bool                                                            m_authEnabled    = false;
    bool                                                            m_detailsVisible = false;
    bool                                                            m_capsLockOn     = false;
    bool                                                            m_capsShown      = false;
    bool                                                            m_errShown       = false;
    bool                                                            m_infoShown      = false;
    bool                                                            m_sawPasswordPrompt = false;
    bool                                                            m_passwordVisible   = true;
    std::string                                                     m_promptText     = "Password";
};
