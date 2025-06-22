const categorias = [
  { nome: "Meditação", imagem: "Meditacao.png", link: "meditacao.html" },
  { nome: "Exercícios físicos", imagem: "Exercicios_fisicos.png", link: "exercicios_fisicos.html" },
  { nome: "Leitura", imagem: "Leitura.png", link: "leitura.html" },
  { nome: "Alimentação saudável", imagem: "Alimentacao_saudavel.png", link: "alimentacao_saudavel.html" },
  { nome: "Rotina de sono", imagem: "Rotina_de_sono.png", link: "rotina_de_sono.html" },
  { nome: "Desconexão digital", imagem: "Desconexao_digital.png", link: "desconexao_digital.html" },
  { nome: "Escrita pessoal", imagem: "Escrita_pessoal.png", link: "escrita_pessoal.html" },
  { nome: "Atividades criativas", imagem: "Atividades_criativas.png", link: "atividades_criativas.html" },
  { nome: "Socialização saudável", imagem: "Socializacao_saudavel.png", link: "socializacao_saudavel.html" },
  { nome: "Organização financeira", imagem: "Organizacao_financeira.png", link: "organizacao_financeira.html" }
];

const carrossel = document.getElementById("carrossel");

categorias.forEach(categoria => {
  const link = document.createElement("a");
  link.href = categoria.link;
  link.classList.add("carrossel-item");
  link.title = categoria.nome;

  const img = document.createElement("img");
  img.src = `assets/${categoria.imagem}`;
  img.alt = categoria.nome;

  const titulo = document.createElement("p");
  titulo.textContent = categoria.nome;

  link.appendChild(img);
  link.appendChild(titulo);
  carrossel.appendChild(link);
});