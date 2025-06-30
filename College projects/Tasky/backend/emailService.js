const nodemailer = require("nodemailer");

const transporter = nodemailer.createTransport({
  service: "gmail",
  auth: {
    user: "seuemail@gmail.com",
    pass: "senha-do-aplicativo", 
  },
});

function enviarEmail(destinatario, tarefasPendentes) {
  const textoTarefas = tarefasPendentes.map((t, i) => `${i + 1}. ${t.titulo}`).join("\n");

  const mailOptions = {
    from: "seuemail@gmail.com",
    to: destinatario,
    subject: "Tarefas Pendentes - TODO List",
    text: `Você ainda tem as seguintes tarefas pendentes:\n\n${textoTarefas}`,
  };

  transporter.sendMail(mailOptions, function (error, info) {
    if (error) {
      console.log("Erro ao enviar e-mail:", error);
    } else {
      console.log("✅ E-mail enviado: " + info.response);
    }
  });
}

module.exports = enviarEmail;