const loginTab = document.getElementById('login-tab');
const registerTab = document.getElementById('register-tab');
const loginSection = document.getElementById('login-section');
const registerSection = document.getElementById('register-section');

loginTab.addEventListener('click', () => {
  loginTab.classList.add('active');
  registerTab.classList.remove('active');
  loginSection.classList.add('active');
  registerSection.classList.remove('active');
});

registerTab.addEventListener('click', () => {
  registerTab.classList.add('active');
  loginTab.classList.remove('active');
  registerSection.classList.add('active');
  loginSection.classList.remove('active');
});

function showAlert(message) {
  alert(message);
}

const registerForm = document.getElementById('register-form');
registerForm.addEventListener('submit', async (e) => {
  e.preventDefault();

  const name = registerForm.name.value.trim();
  const email = registerForm.email.value.trim();
  const password = registerForm.password.value.trim();

  if (!name || !email || !password) {
    showAlert('Por favor, preencha todos os campos para cadastro.');
    return;
  }

  try {
    const response = await fetch('/register', {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({ name, email, password })
    });

    const data = await response.json();

    if (!response.ok) {
      showAlert(data.error || 'Erro ao cadastrar.');
      return;
    }

    showAlert('Cadastro realizado com sucesso!');
    registerForm.reset();
    loginTab.click();

  } catch (err) {
    console.error(err);
    showAlert('Erro de conexão com o servidor.');
  }
});

const loginForm = document.getElementById('login-form');
loginForm.addEventListener('submit', async (e) => {
  e.preventDefault();

  const email = loginForm.email.value.trim();
  const password = loginForm.password.value.trim();

  if (!email || !password) {
    showAlert('Por favor, preencha todos os campos para fazer login.');
    return;
  }

  try {
    const response = await fetch('/login', {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({ email, password })
    });

    const data = await response.json();

    if (!response.ok) {
      showAlert(data.error || 'Erro ao fazer login.');
      return;
    }

    showAlert(`Bem-vindo, ${data.user.name}!`);
    loginForm.reset();

    window.location.href = 'todo.html';

  } catch (err) {
    console.error(err);
    showAlert('Erro de conexão com o servidor.');
  }
});