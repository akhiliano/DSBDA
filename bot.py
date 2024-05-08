import re
import random

class CustomerSupportChatbot:
    def __init__(self):
        self.rules = {
            # Greetings
            r'yo|hi|hello|hey': ['Hello! Welcome to our customer support. How can I assist you today?', 
                              'Hi there! How can I help you?'],

            # Registration query
            r'issue|glitch|register\s*query|create\s*ticket|report\s*issue': ['Sure, I can help you with that. Please describe your issue.'],

            # Common issues and solutions
            r'unable\s*to\s*login|frozen\s*account|login\s*issue': ['Please make sure you are using the correct username and password. If the issue persists, try resetting your password.'],
            r'cannot\s*make\s*payment|transaction\s*problem|payment\s*issue': ['I apologize for the inconvenience. Please provide details of the transaction so we can investigate.'],
            r'product\s*information|features|specifications|need\s*info|tell\s*me\s*details': ['You can find detailed product information on our website or user manual. If you need specific details, feel free to ask.'],

            # Escalation to administration
            r'still\s*there|not\s*resolving|stuck\s*there|still\s*not\s*working|yes|unable\s*to\s*resolve|need\s*assistance|contact\s*admin': ['I am sorry for the inconvenience. Let me escalate your issue to our administration. They will reach out to you soon. Can I help you with anything else!!'],

            # General talking rules
            r'thank\s*you': ['You\'re welcome!', 'Anytime!', 'Glad I could assist you.'],
            r'no|leave\s*it|bye|goodbye': ['Thank you for reaching out. Have a great day!', 'Goodbye! Take care.']
        }

    def respond(self, message):
        for pattern, responses in self.rules.items():
            if re.search(pattern, message, re.IGNORECASE):
                return random.choice(responses)
        return "I'm sorry, it's outside my capacity. Would you like to speak with our administration?"

# Create an instance of the CustomerSupportChatbot
chatbot = CustomerSupportChatbot()

# Test the chatbot
print("Welcome to Customer Support Chatbot!")
print("How can I assist you today?")

while True:
    user_input = input("You: ")
    if user_input.lower() == 'bye':
        print("Customer Support Chatbot: Thank you for reaching out. Have a great day!")
        break
    response = chatbot.respond(user_input)
    print("Customer Support Chatbot:", response)
