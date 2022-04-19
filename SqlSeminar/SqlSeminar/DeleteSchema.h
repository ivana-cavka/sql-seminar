#pragma once
#include "Relation.h"

namespace SqlSeminar {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for DeleteSchema
	/// </summary>
	public ref class DeleteSchema : public System::Windows::Forms::Form
	{
	public:
		DeleteSchema(void)
		{
			InitializeComponent();
			FillComboBoxChooseSchema();
			FillComboBoxChooseDependencies();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DeleteSchema()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ LabelSchema;
	protected:
	private: System::Windows::Forms::ComboBox^ ComboBoxChooseSchema;
	private: System::Windows::Forms::Button^ ButtonDeleteChosenSchema;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ ComboBoxChooseDependencies;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DeleteSchema::typeid));
			this->LabelSchema = (gcnew System::Windows::Forms::Label());
			this->ComboBoxChooseSchema = (gcnew System::Windows::Forms::ComboBox());
			this->ButtonDeleteChosenSchema = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ComboBoxChooseDependencies = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// LabelSchema
			// 
			this->LabelSchema->AutoSize = true;
			this->LabelSchema->BackColor = System::Drawing::Color::LightSlateGray;
			this->LabelSchema->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->LabelSchema->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->LabelSchema->Location = System::Drawing::Point(44, 29);
			this->LabelSchema->Name = L"LabelSchema";
			this->LabelSchema->Size = System::Drawing::Size(389, 20);
			this->LabelSchema->TabIndex = 0;
			this->LabelSchema->Text = L"Odaberite shemu koju želite izbrisati:";
			// 
			// ComboBoxChooseSchema
			// 
			this->ComboBoxChooseSchema->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->ComboBoxChooseSchema->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->ComboBoxChooseSchema->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ComboBoxChooseSchema->FormattingEnabled = true;
			this->ComboBoxChooseSchema->Location = System::Drawing::Point(37, 86);
			this->ComboBoxChooseSchema->Name = L"ComboBoxChooseSchema";
			this->ComboBoxChooseSchema->Size = System::Drawing::Size(405, 28);
			this->ComboBoxChooseSchema->TabIndex = 1;
			this->ComboBoxChooseSchema->SelectedIndexChanged += gcnew System::EventHandler(this, &DeleteSchema::ComboBoxChooseSchema_SelectedIndexChanged);
			// 
			// ButtonDeleteChosenSchema
			// 
			this->ButtonDeleteChosenSchema->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ButtonDeleteChosenSchema->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->ButtonDeleteChosenSchema->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ButtonDeleteChosenSchema->Location = System::Drawing::Point(158, 276);
			this->ButtonDeleteChosenSchema->Name = L"ButtonDeleteChosenSchema";
			this->ButtonDeleteChosenSchema->Size = System::Drawing::Size(154, 30);
			this->ButtonDeleteChosenSchema->TabIndex = 2;
			this->ButtonDeleteChosenSchema->Text = L"IZBRIŠI";
			this->ButtonDeleteChosenSchema->UseVisualStyleBackColor = false;
			this->ButtonDeleteChosenSchema->Click += gcnew System::EventHandler(this, &DeleteSchema::ButtonDeleteChosenSchema_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::LightSlateGray;
			this->label1->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(12, 150);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(459, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Odaberite njoj pripadne funkcijske ovisnosti:";
			// 
			// ComboBoxChooseDependencies
			// 
			this->ComboBoxChooseDependencies->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->ComboBoxChooseDependencies->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->ComboBoxChooseDependencies->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ComboBoxChooseDependencies->FormattingEnabled = true;
			this->ComboBoxChooseDependencies->Location = System::Drawing::Point(37, 207);
			this->ComboBoxChooseDependencies->Name = L"ComboBoxChooseDependencies";
			this->ComboBoxChooseDependencies->Size = System::Drawing::Size(405, 28);
			this->ComboBoxChooseDependencies->TabIndex = 4;
			this->ComboBoxChooseDependencies->SelectedIndexChanged += gcnew System::EventHandler(this, &DeleteSchema::ComboBoxChooseDependencies_SelectedIndexChanged);
			// 
			// DeleteSchema
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(478, 336);
			this->Controls->Add(this->ComboBoxChooseDependencies);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ButtonDeleteChosenSchema);
			this->Controls->Add(this->ComboBoxChooseSchema);
			this->Controls->Add(this->LabelSchema);
			this->Name = L"DeleteSchema";
			this->Text = L"Brisanje sheme";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void FillComboBoxChooseSchema() {
		String^ connString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=sql.seminar;Integrated Security=True";
		SqlConnection sqlConn(connString);
		sqlConn.Open();

		String^ sqlQuery = "SELECT Schema FROM Relation";
		SqlCommand command(sqlQuery, % sqlConn);
		SqlDataReader^ reader = command.ExecuteReader();
		int i = 0;
		while (reader->Read()) {
			String^ value = reader->GetString(i);
			ComboBoxChooseSchema->Items->Add(value);
			i++;
		}
	}

	private: void FillComboBoxChooseDependencies() {
		String^ connString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=sql.seminar;Integrated Security=True";
		SqlConnection sqlConn(connString);
		sqlConn.Open();

		String^ sqlQuery = "SELECT Dependencies FROM Relation";
		SqlCommand command(sqlQuery, % sqlConn);
		SqlDataReader^ reader = command.ExecuteReader();
		int i = 0;
		while (reader->Read()) {
			String^ value = reader->GetString(i);
			ComboBoxChooseDependencies->Items->Add(value);
			i++;
		}
	}

	private: System::Void ComboBoxChooseSchema_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	public: Relation^ relation = nullptr;

	private: System::Void ButtonDeleteChosenSchema_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ schema = this->ComboBoxChooseSchema->Text;
		String^ dependencies = this->ComboBoxChooseDependencies->Text;

		if (schema->Length == 0 || dependencies->Length == 0) {
			MessageBox::Show("Molimo odaberite oba parametra");
			return;
		}

		try {
			String^ connString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=sql.seminar;Integrated Security=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			String^ sqlQuery = "DELETE * FROM Relation WHERE Schema=@schema AND Dependencies=@dependencies";
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@schema", schema);
			command.Parameters->AddWithValue("@dependencies", dependencies);
			
			try {
				command.ExecuteNonQuery();
			}
			catch (Exception^ e) {
				MessageBox::Show("Brisanje nije uspjelo");
			}
		}
		catch (Exception^ e) {
			MessageBox::Show("Baza nedostupna");
			return;
		}
	}
	private: System::Void ComboBoxChooseDependencies_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
