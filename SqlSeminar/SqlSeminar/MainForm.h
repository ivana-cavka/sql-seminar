#pragma once
#include "Relation.h"
#include "AddNewSchema.cpp"
#include "DeleteSchema.cpp"
#include "Program.cpp"

namespace SqlSeminar {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			FillComboBoxSchemas();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ LabelSchema;
	protected:
	private: System::Windows::Forms::Label^ LabelDependencies;
	private: System::Windows::Forms::Label^ LabelKeys;
	private: System::Windows::Forms::Label^ LabelShowDependencies;
	private: System::Windows::Forms::Label^ LabelShowKeys;
	private: System::Windows::Forms::ComboBox^ ComboBoxSchemas;
	private: System::Windows::Forms::Button^ ButtonCalculateKeys;
	private: System::Windows::Forms::Button^ ButtonAddSchema;
	private: System::Windows::Forms::Button^ ButtonDeleteSchema;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->LabelSchema = (gcnew System::Windows::Forms::Label());
			this->LabelDependencies = (gcnew System::Windows::Forms::Label());
			this->LabelKeys = (gcnew System::Windows::Forms::Label());
			this->LabelShowDependencies = (gcnew System::Windows::Forms::Label());
			this->LabelShowKeys = (gcnew System::Windows::Forms::Label());
			this->ComboBoxSchemas = (gcnew System::Windows::Forms::ComboBox());
			this->ButtonCalculateKeys = (gcnew System::Windows::Forms::Button());
			this->ButtonAddSchema = (gcnew System::Windows::Forms::Button());
			this->ButtonDeleteSchema = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// LabelSchema
			// 
			this->LabelSchema->AutoSize = true;
			this->LabelSchema->BackColor = System::Drawing::Color::LightSlateGray;
			this->LabelSchema->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->LabelSchema->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->LabelSchema->Location = System::Drawing::Point(51, 54);
			this->LabelSchema->Name = L"LabelSchema";
			this->LabelSchema->Size = System::Drawing::Size(179, 20);
			this->LabelSchema->TabIndex = 0;
			this->LabelSchema->Text = L"Odaberite schemu:";
			// 
			// LabelDependencies
			// 
			this->LabelDependencies->AutoSize = true;
			this->LabelDependencies->BackColor = System::Drawing::Color::LightSlateGray;
			this->LabelDependencies->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->LabelDependencies->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->LabelDependencies->Location = System::Drawing::Point(51, 107);
			this->LabelDependencies->Name = L"LabelDependencies";
			this->LabelDependencies->Size = System::Drawing::Size(349, 20);
			this->LabelDependencies->TabIndex = 1;
			this->LabelDependencies->Text = L"Funkcijske veze u odabranoj shemi:";
			this->LabelDependencies->Click += gcnew System::EventHandler(this, &MainForm::LabelDependencies_Click);
			// 
			// LabelKeys
			// 
			this->LabelKeys->AutoSize = true;
			this->LabelKeys->BackColor = System::Drawing::Color::LightSlateGray;
			this->LabelKeys->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->LabelKeys->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->LabelKeys->Location = System::Drawing::Point(52, 305);
			this->LabelKeys->Name = L"LabelKeys";
			this->LabelKeys->Size = System::Drawing::Size(209, 20);
			this->LabelKeys->TabIndex = 2;
			this->LabelKeys->Text = L"Izraèunati kljuèevi:";
			// 
			// LabelShowDependencies
			// 
			this->LabelShowDependencies->AutoSize = true;
			this->LabelShowDependencies->BackColor = System::Drawing::Color::LightSlateGray;
			this->LabelShowDependencies->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->LabelShowDependencies->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->LabelShowDependencies->Location = System::Drawing::Point(457, 107);
			this->LabelShowDependencies->Name = L"LabelShowDependencies";
			this->LabelShowDependencies->Size = System::Drawing::Size(59, 20);
			this->LabelShowDependencies->TabIndex = 3;
			this->LabelShowDependencies->Text = L"empty";
			this->LabelShowDependencies->Click += gcnew System::EventHandler(this, &MainForm::LabelShowDependencies_Click);
			// 
			// LabelShowKeys
			// 
			this->LabelShowKeys->AutoSize = true;
			this->LabelShowKeys->BackColor = System::Drawing::Color::LightSlateGray;
			this->LabelShowKeys->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->LabelShowKeys->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->LabelShowKeys->Location = System::Drawing::Point(457, 305);
			this->LabelShowKeys->Name = L"LabelShowKeys";
			this->LabelShowKeys->Size = System::Drawing::Size(59, 20);
			this->LabelShowKeys->TabIndex = 4;
			this->LabelShowKeys->Text = L"empty";
			this->LabelShowKeys->Click += gcnew System::EventHandler(this, &MainForm::LabelShowKeys_Click);
			// 
			// ComboBoxSchemas
			// 
			this->ComboBoxSchemas->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->ComboBoxSchemas->FormattingEnabled = true;
			this->ComboBoxSchemas->Location = System::Drawing::Point(461, 54);
			this->ComboBoxSchemas->Name = L"ComboBoxSchemas";
			this->ComboBoxSchemas->Size = System::Drawing::Size(348, 28);
			this->ComboBoxSchemas->TabIndex = 5;
			this->ComboBoxSchemas->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::ComboBoxSchemas_SelectedIndexChanged);
			// 
			// ButtonCalculateKeys
			// 
			this->ButtonCalculateKeys->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ButtonCalculateKeys->Font = (gcnew System::Drawing::Font(L"Courier New", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->ButtonCalculateKeys->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ButtonCalculateKeys->Location = System::Drawing::Point(55, 228);
			this->ButtonCalculateKeys->Name = L"ButtonCalculateKeys";
			this->ButtonCalculateKeys->Size = System::Drawing::Size(212, 23);
			this->ButtonCalculateKeys->TabIndex = 6;
			this->ButtonCalculateKeys->Text = L"PRONAÐI KLJUÈEVE";
			this->ButtonCalculateKeys->UseVisualStyleBackColor = false;
			this->ButtonCalculateKeys->Click += gcnew System::EventHandler(this, &MainForm::ButtonCalculateKeys_Click);
			// 
			// ButtonAddSchema
			// 
			this->ButtonAddSchema->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ButtonAddSchema->Font = (gcnew System::Drawing::Font(L"Courier New", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->ButtonAddSchema->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ButtonAddSchema->Location = System::Drawing::Point(332, 228);
			this->ButtonAddSchema->Name = L"ButtonAddSchema";
			this->ButtonAddSchema->Size = System::Drawing::Size(216, 23);
			this->ButtonAddSchema->TabIndex = 7;
			this->ButtonAddSchema->Text = L"DODAJ NOVU SHEMU";
			this->ButtonAddSchema->UseVisualStyleBackColor = false;
			this->ButtonAddSchema->Click += gcnew System::EventHandler(this, &MainForm::ButtonAddSchema_Click);
			// 
			// ButtonDeleteSchema
			// 
			this->ButtonDeleteSchema->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ButtonDeleteSchema->Font = (gcnew System::Drawing::Font(L"Courier New", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->ButtonDeleteSchema->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ButtonDeleteSchema->Location = System::Drawing::Point(596, 228);
			this->ButtonDeleteSchema->Name = L"ButtonDeleteSchema";
			this->ButtonDeleteSchema->Size = System::Drawing::Size(213, 23);
			this->ButtonDeleteSchema->TabIndex = 8;
			this->ButtonDeleteSchema->Text = L"IZBRIŠI SHEMU";
			this->ButtonDeleteSchema->UseVisualStyleBackColor = false;
			this->ButtonDeleteSchema->Click += gcnew System::EventHandler(this, &MainForm::ButtonDeleteSchema_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(860, 388);
			this->Controls->Add(this->ButtonDeleteSchema);
			this->Controls->Add(this->ButtonAddSchema);
			this->Controls->Add(this->ButtonCalculateKeys);
			this->Controls->Add(this->ComboBoxSchemas);
			this->Controls->Add(this->LabelShowKeys);
			this->Controls->Add(this->LabelShowDependencies);
			this->Controls->Add(this->LabelKeys);
			this->Controls->Add(this->LabelDependencies);
			this->Controls->Add(this->LabelSchema);
			this->Name = L"MainForm";
			this->Text = L"Relacijske sheme i njihovi kljuèevi";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void FillComboBoxSchemas() {
		String^ connString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=sql.seminar;Integrated Security=True";
		SqlConnection sqlConn(connString);
		sqlConn.Open();

		String^ sqlQuery = "SELECT Relation.Schema FROM dbo.Relation;";
		SqlCommand command(sqlQuery, % sqlConn);
		SqlDataReader^ reader = command.ExecuteReader();
		int i = 0;
		while (reader->Read()) {
			String^ value = reader->GetString(i);
			ComboBoxSchemas->Items->Add(value);
			i++;
		}
	}

	private: System::Void LabelDependencies_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void ComboBoxSchemas_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ connString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=sql.seminar;Integrated Security=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			String^ schema = this->ComboBoxSchemas->Text;
			String^ sqlQuery = "SELECT Dependencies FROM Relation WHERE Schema=@schema";
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@schema", schema);
			SqlDataReader^ reader = command.ExecuteReader();
			if (reader->Read()) {
				LabelShowDependencies->Text = reader->GetString(0);
			}
			else
			{
				MessageBox::Show("Informacija nedostupna");
				return;
			}
		}
		catch (Exception^ e) {
			MessageBox::Show("Baza nedostupna");
			return;
		}
	}

	private: System::Void LabelShowDependencies_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void LabelShowKeys_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	public: Relation^ relation = nullptr;

	private: System::Void ButtonCalculateKeys_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ schema = this->ComboBoxSchemas->Text;
		String^ dependencies = this->LabelShowDependencies->Text;

		if (schema->Length == 0) {
			MessageBox::Show("Molimo odaberite shemu");
			return;
		}

		try {
			String^ connString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=sql.seminar;Integrated Security=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();
			
			String^ sqlQuery = "SELECT Dependencies FROM Relation WHERE Schema=@schema AND Dependencies=@dependencies";
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@schema", schema);
			command.Parameters->AddWithValue("@dependencies", dependencies);

			SqlDataReader^ reader = command.ExecuteReader();
			if (reader->Read()) {
				relation = gcnew Relation;
				relation->id = reader->GetInt32(0);
				relation->schema = reader->GetString(1);
				relation->dependencies = reader->GetString(2);
				cli::array<String^>^ keys = CalculateKeys(schema,dependencies);
				String^ allKeys;
				for (int i = 0;i < keys->Length;i++) {
					allKeys += keys[i];
					allKeys += "\t";
				}
			}
			else {
				MessageBox::Show("Shema nedostupna");
			}
		}
		catch(Exception^ e) {
			MessageBox::Show("Baza nedostupna");
			return;
		}
	}

	private: System::Void ButtonAddSchema_Click(System::Object^ sender, System::EventArgs^ e) {
		SqlSeminar::AddNewSchema addForm;
		addForm.ShowDialog();
	}

	private: System::Void ButtonDeleteSchema_Click(System::Object^ sender, System::EventArgs^ e) {
		SqlSeminar::DeleteSchema deleteForm;
		deleteForm.ShowDialog();
	}
};
}
